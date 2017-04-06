//
// Created by Makenzie Larsen on 3/27/17.
//

#ifndef HW6_DICTIONARY_H
#define HW6_DICTIONARY_H

#include <string>
#include <vector>
#include <stdexcept>
#include "KeyValue.h"

using namespace std;

template <class Key, class Value>
class Dictionary {
private:
    vector<KeyValue<Key, Value>*> dictionary;

public:
    Dictionary() {
        dictionary.reserve(10);
    }

    Dictionary(unsigned long capacity) {
        dictionary.reserve(capacity);
    }

    Dictionary(Dictionary<Key, Value> &first) {
        for (int i = 0; i < first.dictionary.size(); i++) {
            KeyValue<Key, Value> *original = first.dictionary[i];
            KeyValue<Key, Value> *copy = new KeyValue<Key, Value>(*original);
            dictionary.push_back(copy);
        }
    }

    ~Dictionary() {
        for (int i = 0; i < dictionary.size(); i++) {
            delete dictionary[i];
        }
        dictionary.clear();
    }

    unsigned long getCount(){
        return dictionary.size();
    }

    unsigned long getCapacity() {
        return dictionary.capacity();
    }

    void add(Key key, Value value) {
        KeyValue<Key, Value>* keyValue = new KeyValue<Key, Value>(key, value);
        dictionary.push_back(keyValue);
    }

    void edit(Key key, Value value) {
        int index = getIndex(key);
        removeByIndex(index);
        add(key, value);
    }

    KeyValue<Key, Value>* getByIndex(int index) {
        return dictionary[index];
    }

    int getIndex(Key key) {
        for (int i = 0; i < dictionary.size(); i++) {
            if (dictionary[i]->getKey() == key) {
                return i;
            }
        }
        return -1;
    }

    const KeyValue<Key, Value>* getByKey(const Key& key) {
        int index = getIndex(key);
        if (index == -1) {
            throw out_of_range("Key not found.");
        }
        return dictionary[index];
    }

    const KeyValue<Key, Value>* operator[] (const Key& key) {
        return getByKey(key);
    }

    void removeByKey(Key key) {
        int index = getIndex(key);
        if (index == -1) {
            throw out_of_range("Key not found.");
        }
        removeByIndex(index);

    }
    
    void removeByIndex(int index) {
        delete dictionary[index];
        dictionary.erase(dictionary.begin() + index);
    }
};

#endif
