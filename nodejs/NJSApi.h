//
// Created by El Khalil Bellakrid on 01/02/2018.
//

#ifndef ADDONS_TEST_NJSAPI_H
#define ADDONS_TEST_NJSAPI_H


#include <iostream>
#include <node.h>
#include <nan.h>
#include <stdlib.h>
#include <memory>

#include "../src/interface/api.hpp"


using namespace std;
using namespace v8;
using namespace node;

class NJSApi : public Nan::ObjectWrap {

public:

    static void Initialize(Local<Object> target);

    std::shared_ptr<ledgerapp_gen::Api> getApi() {return m_api;};

private:

    NJSApi(shared_ptr<ledgerapp_gen::Api> api)
            :m_api(api)
    {};

    ~NJSApi()
    {};

    static NAN_METHOD(New);
    static NAN_METHOD(Init);

    std::shared_ptr<ledgerapp_gen::Api> m_api;
};

#endif //ADDONS_TEST_NJSAPI_H
