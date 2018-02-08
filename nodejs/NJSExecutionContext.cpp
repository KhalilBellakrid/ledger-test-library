//
//  NJSExecutionContext.cpp
//  ledgerapp_nodejs
//
//  Created by El Khalil Bellakrid on 06/02/2018.
//

#include "NJSExecutionContext.h"
#include "../src/runnable.hpp"

using namespace std;
using namespace node;
using namespace v8;

void NJSExecutionContext::execute(const std::shared_ptr<ledgerapp_gen::Runnable> & runnable){
    //TODO: execute in NodeJS way
    runnable->run();
}

void NJSExecutionContext::delay(const std::shared_ptr<ledgerapp_gen::Runnable> & runnable, int64_t millis){
    //TODO: execute in NodeJS way and introduce delay
    runnable->run();
}

NAN_METHOD(NJSExecutionContext::New) {
    Isolate *isolate = info.GetIsolate();
    if (!info.IsConstructCall()) {
        return Nan::ThrowError("NJSExecutionContext::New: function can only be used as a constructor");
    }
    NJSExecutionContext *obj = new NJSExecutionContext(isolate);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(NJSExecutionContext::Execute){
    Isolate *isolate = info.GetIsolate();
    if(info.Length() != 1){
        return Nan::ThrowError("NJSExecutionContext::Execute needs one argument");
    }
    NJSExecutionContext* obj = Nan::ObjectWrap::Unwrap<NJSExecutionContext>(info.Holder());
    if (info[0]->IsObject() ){
        NJSExecutionContext::execute(isolate, obj, info[0]->ToObject());
    }
}

NAN_METHOD(NJSExecutionContext::Delay){
    //TODO : delay execution
    Isolate *isolate = info.GetIsolate();
    if(info.Length() != 2){
        return Nan::ThrowError("NJSExecutionContext::Delay needs two arguments");
    }
    NJSExecutionContext* obj = Nan::ObjectWrap::Unwrap<NJSExecutionContext>(info.Holder());
    if (info[0]->IsObject() && info[1]->IsNumber()){
        NJSExecutionContext::delay(isolate, obj, info[0]->ToObject(), Nan::To<int64_t>(info[1]).ToChecked());
    }
}

void NJSExecutionContext::execute(Isolate *isolate, NJSExecutionContext *exec_context, Local<Object> task){
    NJSExecutionContext::delay(isolate, exec_context, task, 0);
}

void NJSExecutionContext::delay(Isolate *isolate, NJSExecutionContext *exec_context, Local<Object> task, int64_t millis){
    Nan::HandleScope scope;
    if(isolate && exec_context && task->IsCallable()){
        Local<Value> arg[0];
        auto lambda_task = [&](){
            auto result = task->CallAsFunction(isolate->GetCurrentContext(), isolate->GetCurrentContext()->Global(), 0, arg);
            if(result.ToLocalChecked()->IsStringObject()){
                cout<<"Result received"<<endl;
            }
        };
        auto runnable = make_shared<ledgerapp::Runnable>(lambda_task);
        exec_context->delay(runnable,millis);
    }
}

void NJSExecutionContext::Initialize(Local<Object> target)
{
    Nan::HandleScope scope;
    
    Local<FunctionTemplate> ledgerappTemplate = Nan::New<FunctionTemplate>(NJSExecutionContext::New);
    Local<ObjectTemplate> objectTemplate = ledgerappTemplate->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);
    
    Nan::SetPrototypeMethod(ledgerappTemplate,"Execute",Execute);
    Nan::SetPrototypeMethod(ledgerappTemplate,"Delay",Delay);
    
    ledgerappTemplate->SetClassName(Nan::New<String>("NJSExecutionContext").ToLocalChecked());
    target->Set(Nan::New<String>("NJSExecutionContext").ToLocalChecked(), ledgerappTemplate->GetFunction());
}
