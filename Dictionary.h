//
// Created by Makenzie Larsen on 3/27/17.
//

#ifndef HW6_DICTIONARY_H
#define HW6_DICTIONARY_H

#include <string>
#include "KeyValue.h"

template <typename a_type, typename b_type> class Dictionary {
private:
    KeyValue<a_type, b_type> dictionary[];
    int availableSpace = 0;
    int keyValuesAllocated = 0;
public:
    Dictionary();
    Dictionary(int value);
    Dictionary(Dictionary first);
    ~Dictionary();
    void add(a_type key, b_type value);
    KeyValue getByIndex(int index);
    KeyValue* getByKey(a_type key);
    void removeByKey(a_type key);
    void removeByIndex(int index);
};

#endif
