//
//  NJSLock.cpp
//  ledgerapp_nodejs
//
//  Created by El Khalil Bellakrid on 07/02/2018.
//

#include "NJSLock.h"

void NJSLock::lock(){
    _lock.lock();
}

bool NJSLock::tryLock(){
    return _lock.try_lock();
}

void NJSLock::unlock(){
    _lock.unlock();
}

