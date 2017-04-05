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
        dictionary = new vector();
    }

    Dictionary(unsigned long capacity) {
        dictionary = new vector(capacity);
    }

    Dictionary(Dictionary<Key, Value> &first) {
        dictionary = new vector(first.dictionary);
    }

    ~Dictionary() {
        // TODO do i want to delete all the pointers as well?
        delete dictionary;
    }

    unsigned long getCount(){
        return dictionary.size();
    }

    void add(Key key, Value value) {
        KeyValue<Key, Value>* keyValue = new KeyValue<Key, Value>(key, value);
        dictionary.push_back(keyValue);
    }

    const KeyValue<Key, Value>* getByIndex(int index) {
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
            // todo throw some error
        }
        return dictionary[index];
    }

    const KeyValue<Key, Value>* operator[] (const Key& key) {
        return getByKey(key);
    }

    void removeByKey(Key key) {
        int index = getIndex(key);
        if (index == -1) {
            //TODO: throw error
        }
        removeByIndex(index);

    }

    void removeByIndex(int index) {
        // delete pointer at index?
        dictionary.erase(dictionary.begin() + index);
    }
};

#endif
