//
// Created by El Khalil Bellakrid on 01/02/2018.
//
#include "NJSApi.h"
#include "NJSHttpModule.h"
#include "NJSThreadDispatcher.h"
#include "NJSTransactionListVmObserver.h"

#include "../src/interface/http.hpp"
#include "../src/interface/transaction_list_vm_handle.hpp"

using namespace std;
using namespace v8;
using namespace node;

NAN_METHOD(NJSApi::New){

        if(!info.IsConstructCall()){
            return Nan::ThrowError("NJSApi::New: function can only be used as a constructor");
        }
        if(info.Length() != 2){
            return Nan::ThrowError("NJSApi::New: constructor needs two arguments");
        }
        Local<Context> context = Nan::GetCurrentContext();

        if (info[0]->IsObject() && info[1]->IsObject()) {

            Local<Object> obj_http = info[0]->ToObject(context).ToLocalChecked();
            Local<Object> obj_thread_dispatcher = info[1]->ToObject(context).ToLocalChecked();
            
            if(obj_http.IsEmpty() || obj_thread_dispatcher.IsEmpty()){
                return Nan::ThrowError("NJSApi::New: one of two argument is invalid");
            }

            int count = obj_http->InternalFieldCount();
            int count_dispatcher = obj_thread_dispatcher->InternalFieldCount();

            if(count > 0 && count_dispatcher > 0){
                NJSThreadDispatcher *thread_dispatcher = static_cast<NJSThreadDispatcher *>(Nan::GetInternalFieldPointer(obj_thread_dispatcher,0));
                NJSHttpModule *http = static_cast<NJSHttpModule *>(Nan::GetInternalFieldPointer(obj_http,0));
                if (!http) {
                    return Nan::ThrowError("NJSApi::New: NJSHttpModule object not valid");
                }else if(!thread_dispatcher){
                    return Nan::ThrowError("NJSApi::New: NJSThreadDispatcher object not valid");
                }

                shared_ptr<ledgerapp_gen::Http> sp_http(http);
                shared_ptr<ledgerapp_gen::ThreadDispatcher> sp_thread_dispatcher(thread_dispatcher);
                shared_ptr<ledgerapp_gen::Api> api = ledgerapp_gen::Api::create_api(sp_http,sp_thread_dispatcher);


                NJSApi *obj = new NJSApi(api);
                obj->Wrap(info.This());
                info.GetReturnValue().Set(info.This());

            }else{
                return Nan::ThrowError("NJSApi::New: one of two argument is invalid");
            }
        }
}

void NJSApi::Initialize(Local<Object> target)
{
    Nan::HandleScope scope;

    Local<FunctionTemplate> ledgerappTemplate = Nan::New<FunctionTemplate>(NJSApi::New);
    ledgerappTemplate->InstanceTemplate()->SetInternalFieldCount(1);
    ledgerappTemplate->SetClassName(Nan::New<String>("NJSApi").ToLocalChecked());

    target->Set(Nan::New<String>("NJSApi").ToLocalChecked(), ledgerappTemplate->GetFunction());
}



