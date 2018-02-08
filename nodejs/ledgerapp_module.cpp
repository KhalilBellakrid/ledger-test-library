#include <node.h>
#include <nan.h>

#include "NJSHttpModule.h"
#include "NJSApi.h"
#include "NJSThreadDispatcher.h"
#include "NJSTransactionListVmObserver.h"
#include "NJSCallbackModule.h"

using namespace std;
using namespace v8;
using namespace node;

static void init(Local<Object> target){

    Nan::HandleScope scope;

    NJSHttpModule::Initialize(target);
    NJSCallbackModule::Initialize(target);
    NJSThreadDispatcher::Initialize(target);
    NJSApi::Initialize(target);
    NJSTransactionListVmObserver::Initialize(target);

}

NODE_MODULE(ledgerapp_nodejs, init);
