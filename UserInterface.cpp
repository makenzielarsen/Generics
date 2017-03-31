//
// Created by Makenzie Larsen on 3/29/17.
//

#include <iostream>
#include "UserInterface.h"
#include "Dictionary.h"

using namespace std;

void printDictionaryMenu() {
    cout << "Dictionary Menu" << endl;
    cout << "A - Add Key and Value" << endl;
    cout << "C - Get count" << endl;
    cout << "K - Edit by key" << endl;
    cout << "I - Edit by index" << endl;
    cout << "R - Remove by key" << endl;
    cout << "S - Remove by index" << endl;
    cout << "X - Exit" << endl;
}

bool checkKeyValid(string key) {
    return !(key != "string" || key != "int");
}

void runDictionary(Dictionary currentDictionary) {
    cout << "Welcome to your dictionary" << endl;
    printDictionaryMenu();
    char selection = 'A';
    cin >> selection;
    while (selection != 'X') {
        switch(selection){
            default:
                cout << "Unknown character. Try again." << endl;
                break;
            case 'A':
                string key;
                string value;
                cout << "Input key type: ";
                cin >> key;
                bool isValid = checkKeyValid(key);
                if (isValid) {
                    cout << "Input value type: ";
                    cin >> value;
                    currentDictionary.add(key, value);
                }
                break;
            case 'C':
                cout << "The current key/value count is " << currentDictionary.getCount() << endl;
                break;
            case 'K':
                cout << "Enter the key you want to edit: ";
                cin >> key;
                KeyValue* currentKey = currentDictionary.getByKey(key);
                cout << "Current Key: " <<currentKey->getKey() << endl;
                cout << "Current Value: " << currentKey->getValue() << endl;
                cout << "Enter new key (enter X to leave the same): ";
                cin >> key;
                if (key == "X") {
                    cout << "Nothing was changed." << endl;
                } else {
                    currentKey->setKey(key);
                }
                cout << "Enter new value (enter X to leave the same): ";
                cin >> value;
                if (key == "X") {
                    cout << "Nothing was changed." << endl;
                } else {
                    currentKey->setValue(value);
                }
                cout << "New Key: " <<currentKey->getKey() << endl;
                cout << "New Value: " << currentKey->getValue() << endl;
                break;
            case 'I':
                int index;
                cout << "Enter the index you want to edit: ";
                cin >> index;
                KeyValue* currentIndex = currentDictionary.getByIndex(index);
                cout << "Key: " <<currentIndex->getKey() << endl;
                cout << "Value: " << currentIndex->getValue() << endl;
                break;
            case 'R':
                cout << "Enter the index you want to delete: ";
                cin >> index;
                currentDictionary.removeByIndex(index);
                break;
            case 'S':
                cout << "Enter the key you want to delete: ";
                cin >> key;
                currentDictionary.removeByKey(key);
                break;
        }
        printDictionaryMenu();
        cin >> selection;
    }
}

void printMenu(){
    cout << "Menu:" << endl;
    cout << "C - Create a new dictionary" << endl;
    cout << "D - Delete current dictionary" << endl;
    cout << "X - Exit Program" << endl;
}

Dictionary createDictionary() {
    string key;
    string value;
    int termSize;
    cout << "Input key type: ";
    cin >> key;
    bool isValid = checkKeyValid(key);
    if (isValid) {
        cout << "Input value type: ";
        cin >> value;
        cout << "Enter initial term size: ";
        cin >> termSize;
    }
    Dictionary currentDictionary<key, value>;
    return currentDictionary;
};

void deleteDictionary(Dictionary currentDictionary) {
    currentDictionary.~Dictionary();
    cout << "Dictionary Deleted" << endl;
}

void UserInterface::run() {
    cout << "Welcome to the Dictionary Application" << endl;

    printMenu();

    char selection = 'A';
    cin >> selection;
    while (selection != 'X') {
        switch(selection) {
            default:
                cout << "Unknown character. Try again." << endl;
                break;
            case 'C':
                string keyType = "null";
                string valueType = "null";
                Dictionary currentDictionary<keyType,valueType> = createDictionary();
                runDictionary(currentDictionary);
                break;
            case 'D':
                deleteDictionary(currentDictionary);
                break;
        }
        printMenu();
        cin >> selection;
    }
}
