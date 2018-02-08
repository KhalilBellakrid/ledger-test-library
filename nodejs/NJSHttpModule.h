//
// Created by El Khalil Bellakrid on 26/01/2018.
//
#ifndef ADDONS_TEST_NJSHTTPMODULE_H
#define ADDONS_TEST_NJSHTTPMODULE_H

#include <node.h>
#include <nan.h>
#include <stdlib.h>

#include "../src/interface/http.hpp"
#include "../src/interface/http_callback.hpp"
#include "../src/interface/http_header.hpp"

using namespace std;
using namespace v8;
using namespace node;

class NJSHttpModule : public Nan::ObjectWrap,
                      public ledgerapp_gen::Http {

public:

    static void Initialize(Local<Object> target);

    NJSHttpModule(Isolate *isolate, Local<Object> http);
    ~NJSHttpModule();

    void get(const std::string & url,
             const std::experimental::optional<std::vector<ledgerapp_gen::HttpHeader>> & headers,
             const std::shared_ptr<ledgerapp_gen::HttpCallback> & callback);

private:

    static NAN_METHOD(New);
    static NAN_METHOD(Init);

    Isolate* GetIsolate() { return m_isolate;};

    Isolate* m_isolate;
    Nan::Persistent<Object> m_http;
};

#endif //ADDONS_TEST_NJSHTTPMODULE_H
