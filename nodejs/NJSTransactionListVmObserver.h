//
// Created by El Khalil Bellakrid on 02/02/2018.
//

#ifndef ADDONS_TEST_0_NJSTRANSACTIONLISTVMOBSERVER_H
#define ADDONS_TEST_0_NJSTRANSACTIONLISTVMOBSERVER_H

#include <stdlib.h>
#include <memory>

#include <node.h>
#include <nan.h>

#include "../src/interface/api.hpp"
#include "../src/interface/transaction_list_vm_observer.hpp"
#include "../src/interface/transaction_list_vm_handle.hpp"

using namespace std;
using namespace v8;
using namespace node;

class NJSTransactionListVmObserver : public Nan::ObjectWrap,
                                     public ledgerapp_gen::TransactionListVmObserver {
public:

    NJSTransactionListVmObserver(shared_ptr<ledgerapp_gen::Api> api,
                                 shared_ptr<ledgerapp_gen::TransactionListVmHandle> handle);

    ~NJSTransactionListVmObserver();

    static void Initialize(Local<Object> target);

    void on_update(const std::shared_ptr<ledgerapp_gen::TransactionListVm> & new_data) override;

private:

    static NAN_METHOD(New);
    static NAN_METHOD(Init);

    static NAN_METHOD(start);
    static NAN_METHOD(stop);

    shared_ptr<ledgerapp_gen::TransactionListVmHandle> getHandle(){return m_handle;};
    void setCallback(Local<Object> callback){m_callback.Reset(callback);};

    shared_ptr<ledgerapp_gen::Api> m_api;
    shared_ptr<ledgerapp_gen::TransactionListVmHandle> m_handle;


    Nan::Persistent<Object> m_callback;
};
#endif //ADDONS_TEST_0_NJSTRANSACTIONLISTVMOBSERVER_H
