//
// Created by El Khalil Bellakrid on 28/01/2018.
//

#ifndef ADDONS_TEST_NJSCALLBACKMODULE_H
#define ADDONS_TEST_NJSCALLBACKMODULE_H

#include <stdlib.h>
#include <string>
#include <memory>

#include <node.h>
#include <nan.h>

#include "../src/interface/http_callback.hpp"

using namespace std;
using namespace v8;
using namespace node;

class NJSCallbackModule : public Nan::ObjectWrap {

public:

    static void Initialize(Local<Object> target);

    NJSCallbackModule(const std::shared_ptr<ledgerapp_gen::HttpCallback> &callback);

    ~NJSCallbackModule();

    std::shared_ptr<ledgerapp_gen::HttpCallback> getCallback(){return m_callback;};
    
    static Handle<Object> wrap(const std::shared_ptr<ledgerapp_gen::HttpCallback> &callback);
    static Nan::Persistent<ObjectTemplate> cb_object_prototype;

private:

    static NAN_METHOD(New);
    static NAN_METHOD(Init);
    static NAN_METHOD(onSuccess);

    std::shared_ptr<ledgerapp_gen::HttpCallback> m_callback;
};


#endif //ADDONS_TEST_NJSCALLBACKMODULE_H
