//
// Created by Makenzie Larsen on 3/27/17.
//

#ifndef HW6_DICTIONARY_H
#define HW6_DICTIONARY_H

#include <string>
#include "KeyValue.h"

template <class a_type, class b_type> class Dictionary {
private:
    KeyValue<a_type, b_type> dictionary[];
    int availableSpace = 0;
    int keyValuesAllocated = 0;
public:
    Dictionary();
    Dictionary(int value);
    ~Dictionary();
    void add(a_type key, b_type value);
};

#endif
