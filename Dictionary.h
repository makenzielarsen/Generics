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
        for (int i = 0; i < 10; i++) {
            dictionary[i] = new KeyValue<Key, Value>;
        }
    }

    Dictionary(unsigned long capacity) {
        for (int i = 0; i < capacity; i++) {
            dictionary[i] = new KeyValue<Key, Value>;
        }
    }

    Dictionary(Dictionary<Key, Value> &first) {
        for (int i = 0; i < first.dictionary.size(); i++) {
            dictionary[i] = first.dictionary[i];
        }
    }

    ~Dictionary() {
        for (int i = 0; i < dictionary.size(); i++) {
            delete dictionary[i];
        }
        delete dictionary;
    }

    unsigned long getCount(){
        return dictionary.size();
    }

    void add(Key key, Value value) {
        KeyValue<Key, Value>* keyValue = new KeyValue<Key, Value>(key, value);
        dictionary.push_back(keyValue);
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
        // delete pointer at index?
        dictionary.erase(dictionary.begin() + index);
    }
};

#endif
