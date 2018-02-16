//
// Created by El Khalil Bellakrid on 28/01/2018.
//
#include "NJSCallbackModule.h"

Nan::Persistent<ObjectTemplate> NJSCallbackModule::cb_object_prototype;

NJSCallbackModule::NJSCallbackModule(const std::shared_ptr<ledgerapp_gen::HttpCallback> &callback)
                                    :m_callback(callback)
{}

NJSCallbackModule::~NJSCallbackModule()
{
    //cb_object_prototype.Reset();
}

NAN_METHOD(NJSCallbackModule::New) {

    if (info.IsConstructCall()) {
            return Nan::ThrowError("NJSCallbackModule::New: one of two argument is invalid");
    }

    NJSCallbackModule *obj = new NJSCallbackModule(nullptr);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(NJSCallbackModule::onSuccess){

    if(!info[0]->IsString()){
        return Nan::ThrowError("NJSCallbackModule::onSuccess: one argument should be a string");
    }

    NJSCallbackModule* obj = Nan::ObjectWrap::Unwrap<NJSCallbackModule>(info.Holder());

    Local<String> result = info[0]->ToString();
    Nan::Utf8String utf8(result);
    obj->getCallback()->on_success(0,*utf8);
}

Handle<Object> NJSCallbackModule::wrap(const std::shared_ptr<ledgerapp_gen::HttpCallback> &callback) {
    Local<ObjectTemplate> local_obj_template = Nan::New(cb_object_prototype);
    
    Handle<Object> obj;
    if(! local_obj_template.IsEmpty()){
        obj = local_obj_template->NewInstance();
        NJSCallbackModule *cb = new NJSCallbackModule(callback);
        if(cb){
            cb->Wrap(obj);
        }else{
            Nan::ThrowError("NJSCallbackModule::wrap: failed to wrap callback");
        }
    }else{
        Nan::ThrowError("NJSCallbackModule::wrap: callback's object template not valid");
    }
    return obj;
}

void NJSCallbackModule::Initialize(Local<Object> target)
{
    Nan::HandleScope scope;

    Local<FunctionTemplate> ledgerappTemplate = Nan::New<FunctionTemplate>(NJSCallbackModule::New);
    Local<ObjectTemplate> objectTemplate = ledgerappTemplate->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    ledgerappTemplate->SetClassName(Nan::New<String>("NJSCallbackModule").ToLocalChecked());
    Nan::SetPrototypeMethod(ledgerappTemplate,"onSuccess",onSuccess);
    
    cb_object_prototype.Reset(objectTemplate);
    
    target->Set(Nan::New<String>("NJSCallbackModule").ToLocalChecked(), ledgerappTemplate->GetFunction());
}
