//
// Created by El Khalil Bellakrid on 26/01/2018.
//
#include "NJSHttpModule.h"
#include "NJSCallbackModule.h"

NJSHttpModule::NJSHttpModule(Isolate *isolate, Local<Object> http):m_isolate(isolate)
{
    m_http.Reset(http);
}

NJSHttpModule::~NJSHttpModule()
{
    m_http.Reset();
}

NAN_METHOD(NJSHttpModule::New){

    if (!info.IsConstructCall()) {
        return Nan::ThrowError("NJSHttpModule function can only be used as a constructor");
    }

    if (info.Length() == 1) {
        return Nan::ThrowError("NJSHttpModule constructor requires one argument");
    }

    Isolate *isolate = info.GetIsolate();

    try {
        if (info[0]->IsObject()) {
            NJSHttpModule* js_http = new NJSHttpModule(isolate,info[0]->ToObject());
            js_http->Wrap(info.This());
            info.GetReturnValue().Set(info.This());

        } else {
            return Nan::ThrowError("NJSHttpModule::New: requires a request as argument");
        }
    }
    catch (const string &error) {
        Nan::ThrowError(error.c_str());
    }
}


void NJSHttpModule::get(const std::string & url,
                        const std::experimental::optional<std::vector<ledgerapp_gen::HttpHeader>> & headers,
                        const std::shared_ptr<ledgerapp_gen::HttpCallback> & callback){

    Nan::HandleScope scope;

    Isolate *isolate = GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    //Header object
    bool bInvalidHeaders = false;
    auto header = Object::New(isolate);
    if(headers){

        size_t headers_size = (*headers).size();
        if(headers_size > 0){
            auto field_prop = header->CreateDataProperty(context,uint32_t(0),String::NewFromUtf8(isolate,(*headers)[0].field.c_str()));
            auto value_prop = header->CreateDataProperty(context,uint32_t(1),String::NewFromUtf8(isolate,(*headers)[0].value.c_str()));
            bInvalidHeaders = (!field_prop.FromJust() || !value_prop.FromJust());
        }

        if(bInvalidHeaders)
            return Nan::ThrowError("NJSHttpModule::get: invalid headers");

        //Arguments for http request
        Handle<Value> args[3];
        //Url
        args[0] = String::NewFromUtf8(isolate, url.c_str());

        //Callback
        if(headers_size > 0){
            args[1] = header;
        }else{
            args[1] = String::NewFromUtf8(isolate, "No headers");
        }

        Local<Object> local_http = Local<Object>::New(isolate, m_http);
        Handle<Object> js_callack = NJSCallbackModule::wrap(isolate, callback);

        if(js_callack.IsEmpty()){
            return Nan::ThrowError("NJSHttpModule::get: problem while retrieving native callback");
        }else if(local_http->IsObject() && local_http->IsCallable()){
            args[2] = js_callack;
            auto result = local_http->CallAsFunction(context, context->Global(),3,args);
            if(result.IsEmpty()){
                return Nan::ThrowError("NJSHttpModule::get: problem while calling native callback");
            }
        }
    }
}

void NJSHttpModule::Initialize(Local<Object> target)
{
    Nan::HandleScope scope;

    Local<FunctionTemplate> ledgerappTemplate = Nan::New<FunctionTemplate>(NJSHttpModule::New);
    Local<ObjectTemplate> objectTemplate = ledgerappTemplate->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    ledgerappTemplate->SetClassName(Nan::New<String>("NJSHttpModule").ToLocalChecked());

    target->Set(Nan::New<String>("NJSHttpModule").ToLocalChecked(), ledgerappTemplate->GetFunction());
}
