//
//  NJSExecutionContext.hpp
//  ledgerapp_nodejs
//
//  Created by El Khalil Bellakrid on 06/02/2018.
//

#ifndef NJSExecutionContext_h
#define NJSExecutionContext_h

#include <iostream>
#include <nan.h>
#include "../src/interface/execution_context.hpp"

using namespace std;
using namespace node;
using namespace v8;

class NJSExecutionContext : public Nan::ObjectWrap,
                            public ledgerapp_gen::ExecutionContext,
                            public enable_shared_from_this<NJSExecutionContext>{
    
public:
    
    static void Initialize(Local<Object> target);
    
    void execute(const std::shared_ptr<ledgerapp_gen::Runnable> & runnable);
    void delay(const std::shared_ptr<ledgerapp_gen::Runnable> & runnable, int64_t millis);

    NJSExecutionContext(Isolate *isolate):m_isolate(isolate){};
    ~NJSExecutionContext(){};

private:
    static void execute(Isolate *isolate, NJSExecutionContext *exec_context, Local<Object> task);

    static void delay(Isolate *isolate, NJSExecutionContext *exec_context, Local<Object> task, int64_t millis);

    static NAN_METHOD(New);

    static NAN_METHOD(Init);
    static NAN_METHOD(Execute);

    static NAN_METHOD(Delay);

    Isolate *m_isolate;
};
#endif /* NJSExecutionContext_h */
