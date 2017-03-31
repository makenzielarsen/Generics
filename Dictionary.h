//
// Created by Makenzie Larsen on 3/27/17.
//

#ifndef HW6_DICTIONARY_H
#define HW6_DICTIONARY_H

#include <string>
#include "KeyValue.h"

using namespace std;

template <class a_type, class b_type>
class Dictionary {
private:
    KeyValue<a_type, b_type>* dictionary[];
    int availableSpace = 0;
    int keyValuesAllocated = 0;
public:
    Dictionary() {
        dictionary[10] = new KeyValue<a_type, b_type>;
        availableSpace = 10;
    }

    Dictionary(int value) {
        dictionary[value] = new KeyValue<a_type, b_type>;
        availableSpace = value;
    }

    Dictionary(Dictionary &first) {
        dictionary[first.availableSpace] = new KeyValue<a_type, b_type>;
        std::copy(first.dictionary, first.dictionary + first.keyValuesAllocated, dictionary);
    }

    ~Dictionary() {
        delete[](dictionary);
    }

    int getCount(){
        return keyValuesAllocated;
    }

    void add(a_type key, b_type value) {
        if (availableSpace <= keyValuesAllocated) {
            while (availableSpace <= keyValuesAllocated) {
                availableSpace = availableSpace * 2;
            }
            KeyValue<a_type, b_type>* temp[availableSpace];
            for (int i = 0; i < availableSpace; i++) {
                temp[i] = new KeyValue<a_type, b_type>;
            }

            std::fill(temp, temp + availableSpace, 0);
            std::copy(dictionary, dictionary + keyValuesAllocated, temp);

            if (keyValuesAllocated) {
                delete[](dictionary);
            }
            dictionary = temp;
        }
        dictionary[keyValuesAllocated + 2] = new KeyValue<a_type, b_type>(key, value);
        keyValuesAllocated += 1;
    }

    KeyValue<a_type, b_type>* getByIndex(int index) {
        try {
            if (index < 0 || index > keyValuesAllocated - 1) {
                throw 42;
            }
        } catch (int i) {
            cout << "Invalid index given. Try again." << endl;
            cin >> index;
        }

        return dictionary[index];
    }

    KeyValue<a_type, b_type>* getByKey(a_type key) {
        for (int i = 0; i < keyValuesAllocated; i++) {
            if (dictionary[i]->getKey() == key){
                return dictionary[i];
            }
        }
        try {
            if (key == NULL) {
                throw 42;
            } else {
                throw "yikes";
            }
        } catch (int i) {
            cout << "Null Key. Try again." << endl;
        } catch (string s){
            cout << "Key not found. Try again." << endl;
        }
        return dictionary[0];
    }

    int getIndex(KeyValue<a_type, b_type>* key) {
        for (int i = 0; i < keyValuesAllocated; i++) {
            if (dictionary[i]->getKey() == key->getKey()) {
                return i;
            }
        }
        return -1;
    }

    void removeByKey(a_type key) {
        try {
            if (key == NULL) {
                throw 42;
            }
        } catch (int i) {
            cout << "Null Key. Try again." << endl;
        }
        KeyValue<a_type, b_type>* temp = getByKey(key);
        try {
            if (temp == dictionary[0] && temp->getValue() != dictionary[0]->getValue()) {
                throw "yikes";
            }
        } catch (string s){
            cout << "Key not found. Try again." << endl;
        }
        if (temp) {
            delete temp;
        }
        int index = getIndex(temp);
        for (int i = index + 1; i < keyValuesAllocated - 1; ++i) {
            dictionary[i] = dictionary[i + 1];
        }

    }

    void removeByIndex(int index) {
        KeyValue<a_type, b_type>* temp = getByIndex(index);
        if (temp) {
            delete temp;
        }

        for (int i = index + 1; i < keyValuesAllocated - 1; ++i) {
            dictionary[i] = dictionary[i + 1];
        }
    }
};

#endif
