// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from derivings.djinni

#include "NativeRecordWithDerivings.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeRecordWithDerivings::NativeRecordWithDerivings() = default;

NativeRecordWithDerivings::~NativeRecordWithDerivings() = default;

auto NativeRecordWithDerivings::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRecordWithDerivings>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I8::fromCpp(jniEnv, c.eight)),
                                                           ::djinni::get(::djinni::I16::fromCpp(jniEnv, c.sixteen)),
                                                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c.thirtytwo)),
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.sixtyfour)),
                                                           ::djinni::get(::djinni::F32::fromCpp(jniEnv, c.fthirtytwo)),
                                                           ::djinni::get(::djinni::F64::fromCpp(jniEnv, c.fsixtyfour)),
                                                           ::djinni::get(::djinni::Date::fromCpp(jniEnv, c.d)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.s)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRecordWithDerivings::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 9);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRecordWithDerivings>::get();
    return {::djinni::I8::toCpp(jniEnv, jniEnv->GetByteField(j, data.field_mEight)),
            ::djinni::I16::toCpp(jniEnv, jniEnv->GetShortField(j, data.field_mSixteen)),
            ::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_mThirtytwo)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_mSixtyfour)),
            ::djinni::F32::toCpp(jniEnv, jniEnv->GetFloatField(j, data.field_mFthirtytwo)),
            ::djinni::F64::toCpp(jniEnv, jniEnv->GetDoubleField(j, data.field_mFsixtyfour)),
            ::djinni::Date::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mD)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mS))};
}

}  // namespace djinni_generated