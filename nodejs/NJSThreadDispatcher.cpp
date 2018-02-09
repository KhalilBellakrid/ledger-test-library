//  NJSThreadDispatcher.cpp
//  ledgerapp_nodejs
//
//  Created by El Khalil Bellakrid on 06/02/2018.
//

#include "NJSThreadDispatcher.h"
#include "NJSExecutionContext.h"
#include "NJSLock.h"

#include "../src/ledgerapp.hpp"

shared_ptr<ledgerapp_gen::ExecutionContext> NJSThreadDispatcher::getSerialExecutionContext(const string & name){

    setFirstContextKey(name);
    
    auto exec_ctx = make_shared<NJSExecutionContext>();

    if(m_contexts.size() > 0){
        auto search = m_contexts.find(getFirstContextKey());
        if(search == m_contexts.end()){
            m_contexts.insert(pair<string,shared_ptr<ledgerapp_gen::ExecutionContext>>(name,exec_ctx));
        }
    }else{
        m_contexts.insert(pair<string,shared_ptr<ledgerapp_gen::ExecutionContext>>(name,exec_ctx));
    }

    return exec_ctx;
}

shared_ptr<ledgerapp_gen::ExecutionContext> NJSThreadDispatcher::getThreadPoolExecutionContext(const string & name){
    //TODO: same for the moment should be implemented later
    return getSerialExecutionContext(name);
}

shared_ptr<ledgerapp_gen::ExecutionContext> NJSThreadDispatcher::getMainExecutionContext(){
    //Take first one serial context initialized
    auto search = m_contexts.find(getFirstContextKey());
    if(search != m_contexts.end()){
        return search->second;
    }
    //Otherwise instantiate another one
    setFirstContextKey(ledgerapp::MAIN_EXECUTION_CONTEXT);
    return getSerialExecutionContext(ledgerapp::MAIN_EXECUTION_CONTEXT);
}

shared_ptr<ledgerapp_gen::Lock> NJSThreadDispatcher::newLock(){
    //TODO : to implement
    return make_shared<NJSLock>();
}

NAN_METHOD(NJSThreadDispatcher::New) {
        if (!info.IsConstructCall()) {
            return Nan::ThrowError("NJSThreadDispatcher::New: function can only be used as a constructor");
        }
        NJSThreadDispatcher *obj = new NJSThreadDispatcher();
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
}

void NJSThreadDispatcher::setFirstContextKey(const string &name){
    if(m_first_context.size() == 0){
            m_first_context = name;
    }
}

void NJSThreadDispatcher::Initialize(Local<Object> target)
{
    Nan::HandleScope scope;
    
    Local<FunctionTemplate> ledgerappTemplate = Nan::New<FunctionTemplate>(NJSThreadDispatcher::New);
    Local<ObjectTemplate> objectTemplate = ledgerappTemplate->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);
    
    ledgerappTemplate->SetClassName(Nan::New<String>("NJSThreadDispatcher").ToLocalChecked());

    target->Set(Nan::New<String>("NJSThreadDispatcher").ToLocalChecked(), ledgerappTemplate->GetFunction());
}
