//
//  NJSThreadDispatcher.hpp
//  ledgerapp_nodejs
//
//  Created by El Khalil Bellakrid on 06/02/2018.
//
#ifndef NJSThreadDispatcher_h
#define NJSThreadDispatcher_h

#include <map>
#include <nan.h>
#include "../src/interface/thread_dispatcher.hpp"
#include "../src/interface/execution_context.hpp"
#include "../src/interface/lock.hpp"

using namespace std;
using namespace node;
using namespace v8;

class NJSThreadDispatcher : public Nan::ObjectWrap, public ledgerapp_gen::ThreadDispatcher {
    
public:

    NJSThreadDispatcher(Isolate *isolate): m_isolate(isolate){};
    ~NJSThreadDispatcher(){};

    static void Initialize(Local<Object> target);
    
    shared_ptr<ledgerapp_gen::ExecutionContext> getSerialExecutionContext(const string & name) override;
    shared_ptr<ledgerapp_gen::ExecutionContext> getThreadPoolExecutionContext(const string & name) override;
    shared_ptr<ledgerapp_gen::ExecutionContext> getMainExecutionContext() override;
    shared_ptr<ledgerapp_gen::Lock> newLock() override;

private:

    static NAN_METHOD(New);
    static NAN_METHOD(Init);

    void setFirstContextKey(const string &name);
    string getFirstContextKey(){return m_first_context;};

    map<string,shared_ptr<ledgerapp_gen::ExecutionContext>> m_contexts;
    string m_first_context;

    Isolate *m_isolate;
};

#endif /* NJSThreadDispatcher_h */
