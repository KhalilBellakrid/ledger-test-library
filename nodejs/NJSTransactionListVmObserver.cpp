//
// Created by El Khalil Bellakrid on 02/02/2018.
//
#include <iostream>
#include "NJSTransactionListVmObserver.h"
#include "NJSApi.h"

#include "../src/interface/transaction_list_vm.hpp"
#include "../src/interface/transaction_list_vm_cell.hpp"
#include "../src/interface/api.hpp"

using namespace std;
using namespace v8;
using namespace node;

NJSTransactionListVmObserver::NJSTransactionListVmObserver(Isolate *isolate,
                                                           shared_ptr<ledgerapp_gen::Api> api,
                                                           shared_ptr<ledgerapp_gen::TransactionListVmHandle> handle)
                                                            :m_isolate(isolate),m_api(api),m_handle(handle)
{}
NJSTransactionListVmObserver::~NJSTransactionListVmObserver()
{
    m_callback.Reset();
}

NAN_METHOD(NJSTransactionListVmObserver::New){

    Isolate *isolate = info.GetIsolate();

    if(!info.IsConstructCall()){
        return Nan::ThrowError("NJSTransactionListVmObserver::New: function can only be used as a constructor");
    }
    if (!info[0]->IsObject()){
        return Nan::ThrowError("NJSTransactionListVmObserver::New: constructor needs one argument");
    }

    NJSApi *js_api = static_cast<NJSApi *>(Nan::GetInternalFieldPointer(info[0].As<Object>(),0));
    if (!js_api) {
        return Nan::ThrowError("NJSTransactionListVmObserver::New: argument (Api) not valid");
    }

    auto api = js_api->getApi();
    if(api){
        auto handle = api->observer_transaction_list();
        if(handle){
            NJSTransactionListVmObserver *obj = new NJSTransactionListVmObserver(isolate, api, handle);
            if(obj){
                obj->Wrap(info.This());
                info.GetReturnValue().Set(info.This());
            }
        }
    }
}

NAN_METHOD(NJSTransactionListVmObserver::start){

    if(info.Length() != 2){
        return Nan::ThrowError("NJSTransactionListVmObserver::start needs two arguments, array of addresses and a callback function");
    }

    NJSTransactionListVmObserver* observer = Nan::ObjectWrap::Unwrap<NJSTransactionListVmObserver>(info.This());
    if(!observer){
        return Nan::ThrowError("NJSTransactionListVmObserver::start failed to unwrap observer");
    }

    if(!info[1]->IsObject()){
        return Nan::ThrowError("NJSTransactionListVmObserver::start invalid second argument, must be a function");
    }else{
        observer->setCallback(info[1]->ToObject());
    }

    vector<string> addresses;

    if(info[0]->IsString()){
        String::Utf8Value js_address(info[0]->ToString());
        addresses.emplace_back(string(*js_address));
    }else if(info[0]->IsArray()){
        Local<Array> array = Local<Array>::Cast(info[0]);
        uint32_t nb_addresses = array->Length();
        for(uint32_t i = 0; i < nb_addresses; i++){
            if(array->Get(i)->IsString()){
                String::Utf8Value js_address(array->Get(i)->ToString());
                addresses.emplace_back(string(*js_address));
            }
        }
    }else{
        return Nan::ThrowError("NJSTransactionListVmObserver::start called with invalid argument");
    }

    if(observer){
        shared_ptr<ledgerapp_gen::TransactionListVmHandle> handle = observer->getHandle();
        shared_ptr<ledgerapp_gen::TransactionListVmObserver> shared_observer(observer);
        if(handle){
            observer->Ref();
            handle->start(shared_observer, addresses);
        }
    }
}

NAN_METHOD(NJSTransactionListVmObserver::stop){

    if(info.Length() != 0){
        return Nan::ThrowError("NJSTransactionListVmObserver::stop called with wrong parameters");
    }

    NJSTransactionListVmObserver *observer = Nan::ObjectWrap::Unwrap<NJSTransactionListVmObserver>(info.This());
    if(observer){
        shared_ptr<ledgerapp_gen::TransactionListVmHandle> handle = observer->getHandle();
        if(handle){
            handle->stop();
            cout<<"Unrefing"<<endl;
            observer->Unref();
        }
    }
}

void NJSTransactionListVmObserver::on_update(const std::shared_ptr<ledgerapp_gen::TransactionListVm> & new_data){

    Nan::HandleScope scope;

    int32_t tx_nb = new_data->count();

    Isolate *isolate = getIsolate();

    Local<Array> txs_array = Array::New(isolate);
    for(int32_t i = 0; i < tx_nb ; i++){
        ledgerapp_gen::TransactionListVmCell cell = *(new_data->getTransaction(i));
        txs_array->Set((int)i,String::NewFromUtf8(isolate, cell.tx_data.c_str()));
    }

    auto context = isolate->GetCurrentContext();
    Handle<Value> args[1]{txs_array};
    Local<Object> local_cb = Local<Object>::New(isolate,m_callback);
    if(local_cb.IsEmpty()){
        return Nan::ThrowError("NJSTransactionListVmObserver::on_update called with non valid callback");
    }

    auto result = local_cb->CallAsFunction(context, context->Global(),1,args);
    if(result.IsEmpty()){
        return Nan::ThrowError("NJSTransactionListVmObserver::on_update failed callback");
    }

}

void NJSTransactionListVmObserver::Initialize(Local<Object> target)
{
    Nan::HandleScope scope;

    Local<FunctionTemplate> ledgerappTemplate = Nan::New<FunctionTemplate>(NJSTransactionListVmObserver::New);
    ledgerappTemplate->InstanceTemplate()->SetInternalFieldCount(1);
    ledgerappTemplate->SetClassName(Nan::New<String>("NJSTransactionListVmObserver").ToLocalChecked());

    Nan::SetPrototypeMethod(ledgerappTemplate,"start",start);
    Nan::SetPrototypeMethod(ledgerappTemplate,"stop",stop);

    target->Set(Nan::New<String>("NJSTransactionListVmObserver").ToLocalChecked(), ledgerappTemplate->GetFunction());
}

