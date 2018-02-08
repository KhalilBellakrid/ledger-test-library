//
//  NJSLock.hpp
//  ledgerapp_nodejs
//
//  Created by El Khalil Bellakrid on 07/02/2018.
//

#ifndef NJSLock_h
#define NJSLock_h

#include <iostream>
#include <mutex>

using namespace std;

#include "../src/interface/lock.hpp"
class NJSLock : public ledgerapp_gen::Lock {
public:
    NJSLock():_lock(_mutex)
    {};
    ~NJSLock()
    {
        _lock.unlock();
    };
    void lock();
    bool tryLock();
    void unlock();
private:
    recursive_mutex _mutex;
    unique_lock<recursive_mutex> _lock;
};
#endif /* NJSLock_h */
