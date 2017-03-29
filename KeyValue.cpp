//
// Created by Makenzie Larsen on 3/27/17.
//

#include <cstdlib>
#include <exception>
#include "KeyValue.h"

template <class a_type, class b_type> KeyValue::KeyValue() {
    key = NULL;
    value = NULL;
}

template <class a_type, class b_type> KeyValue::KeyValue(a_type Key, b_type Value) {
    key = Key;
    value = Value;
}

template <class a_type, class b_type> KeyValue::KeyValue(KeyValue first) {
    key = first.getKey();
    value = first.getValue();
}

class myexception: public exception {

};

template <class a_type, class b_type> void KeyValue::setKey(a_type newKey) {
    // if key is invalid throw exception
    key = newKey;
}
