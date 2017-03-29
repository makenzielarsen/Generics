//
// Created by Makenzie Larsen on 3/27/17.
//

#ifndef HW6_KEYVALUE_H
#define HW6_KEYVALUE_H

template <typename a_type, typename b_type>
class KeyValue {
private:
    a_type key;
    b_type value;
public:
    KeyValue() {
        key = NULL;
        value = NULL;
    }

    KeyValue(a_type Key, b_type Value) {
        key = Key;
        value = Value;
    }

    KeyValue(KeyValue first) {
        key = first.getKey();
        value = first.getValue();
    }

    a_type getKey(){
        return key;
    }

    b_type getValue(){
        return value;
    }

    void setKey(a_type newKey) {
        // if key is invalid throw exception
        key = newKey;
    }

    void setValue(b_type newValue) {
        value = newValue;
    }

};

#endif
