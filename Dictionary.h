//
// Created by Makenzie Larsen on 3/27/17.
//

#ifndef HW6_DICTIONARY_H
#define HW6_DICTIONARY_H

#include <string>
#include "KeyValue.h"

template <class a_type, class b_type>
class Dictionary {
private:
    KeyValue<a_type, b_type> dictionary[];
    int availableSpace = 0;
    int keyValuesAllocated = 0;
public:
    Dictionary() {
        dictionary = new KeyValue<a_type, b_type>[10];
        availableSpace = 10;
    }

    Dictionary(int value) {
        dictionary = new KeyValue<a_type, b_type>[value];
        availableSpace = value;
    }

    Dictionary(Dictionary first) {
        dictionary = new KeyValue<a_type, b_type>[first.availableSpace];
        std::copy(first.dictionary, first.dictionary + first.keyValuesAllocated, dictionary);
    }

    ~Dictionary() {
        delete[](dictionary);
    }

    void add(a_type key, b_type value) {
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

    KeyValue getByIndex(int index) {
        // if index is invalid throw an exception
        return dictionary[index];
    }

    KeyValue* getByKey(a_type key) {
        for (int i = 0; i < keyValuesAllocated; i++) {
            if (dictionary[i].getKey() == key){
                return &dictionary[i];
            }
        }
        return &dictionary[0];
    }

    void removeByKey(a_type key) {
        KeyValue* temp = getByKey(key);
        if (temp) {
            delete temp;
        }
        //delete from array
    }

    void removeByIndex(int index) {

    }
};

#endif
