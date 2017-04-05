//
// Created by Makenzie Larsen on 3/27/17.
//

#ifndef HW6_KEYVALUE_H
#define HW6_KEYVALUE_H

#include <cmath>

template <typename Key, typename Value>
class KeyValue {
private:
    Key key;
    Value value;
public:
    KeyValue() {
        key = NAN;
        value = NAN;
    }

    KeyValue(Key k, Value v) {
        key = k;
        value = v;
    }

    KeyValue(KeyValue &first) {
        key = first.getKey();
        value = first.getValue();
    }

    Key getKey(){
        return key;
    }

    Value getValue(){
        return value;
    }

    void setKey(Key newKey) {
        key = newKey;
    }

    void setValue(Value newValue) {
        value = newValue;
    }

};

#endif
