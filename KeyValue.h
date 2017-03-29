//
// Created by Makenzie Larsen on 3/27/17.
//

#ifndef HW6_KEYVALUE_H
#define HW6_KEYVALUE_H

template <typename a_type, typename b_type> class KeyValue {
private:
    a_type key;
    b_type value;
public:
    KeyValue();
    KeyValue(a_type Key, b_type Value);
    KeyValue(KeyValue first);
    a_type getKey(){ return key; }
    b_type getValue(){ return value; }
    void setKey(a_type newKey);
    void setValue(b_type newValue) { value = newValue; }

};

#endif
