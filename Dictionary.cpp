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
#include <algorithm>
#include "Dictionary.h"

Dictionary<typename a_type, typename b_type>::Dictionary() {
    dictionary = new KeyValue<a_type, b_type>[10];
    availableSpace = 10;
}

Dictionary<typename a_type, typename b_type>::Dictionary(int value) {
    dictionary = new KeyValue<a_type, b_type>[value];
    availableSpace = value;
}

Dictionary::Dictionary(Dictionary first) {
    dictionary = new KeyValue<a_type, b_type>[first.availableSpace];
    std::copy(first.dictionary, first.dictionary + first.keyValuesAllocated, dictionary);
}

Dictionary<typename a_type, typename b_type>::~Dictionary() {
    delete[](dictionary);
}

template <typename a_type, typename b_type> void Dictionary<class a_type, class b_type>::add(typename a_type, typename b_type) {
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
    //dictionary[keyValuesAllocated + 2] = KeyValue<a_type, b_type>;
    keyValuesAllocated += 1;
}

KeyValue Dictionary::getByIndex(int index) {
    // if index is invalid throw an exception
    return dictionary[index];
}

template <typename a_type, typename b_type> KeyValue* Dictionary::getByKey(a_type key) {
    for (int i = 0; i < keyValuesAllocated; i++) {
        if (dictionary[i].getKey() == key){
            return &dictionary[i];
        }
    }
    return &dictionary[0];
}

template <typename a_type, class b_type> void Dictionary::removeByKey(a_type key) {
    KeyValue* temp = getByKey(key);
    if (temp) {
        delete temp;
    }
    //delete from array
}
