//
// Created by Makenzie Larsen on 3/27/17.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include <cstdint>
#include <string>
#include "Dictionary.h"

template <class a_type, class b_type> Dictionary<class a_type, class b_type>::Dictionary() {
    dictionary = new KeyValue<a_type, b_type>[10];
    availableSpace = 10;
}

template <class a_type, class b_type> Dictionary<class a_type, class b_type>::Dictionary(int value) {
    dictionary = new KeyValue<a_type, b_type>[value];
    availableSpace = value;
}

template <class a_type, class b_type> Dictionary<class a_type, class b_type>::~Dictionary() {
    delete[](dictionary);
}

template <class a_type, class b_type> void Dictionary<class a_type, class b_type>::add(class a_type, class b_type) {
    if (availableSpace <= keyValuesAllocated) {
        while (availableSpace <= keyValuesAllocated) {
            availableSpace = availableSpace * 2;
        }
        KeyValue<a_type, b_type>* temp = new KeyValue<a_type, b_type>[availableSpace];

        std::fill(temp, temp + availableSpace, 0);
        std::copy(dictionary, dictionary + keyValuesAllocated, temp);

        if (keyValuesAllocated) {
            delete[](dictionary);
        }
        dictionary = temp;
    }
    dictionary[keyValuesAllocated + 2] = KeyValue<a_type, b_type>;
    keyValuesAllocated += 1;
}
