//
// Created by Makenzie Larsen on 3/29/17.
//

#include <iostream>
#include "UserInterface.h"
#include "KeyValue.h"
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

template<typename Key, typename Value>
void handleA(Dictionary<Key, Value> currentDictionary) {
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
}

template<typename Key, typename Value>
void handleK(Dictionary<Key, Value> currentDictionary){
    string key;
    string value;
    cout << "Enter the key you want to edit: ";
    cin >> key;
    KeyValue<Key, Value>* currentKey = currentDictionary.getByKey(key);
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
}

template<typename Key, typename Value>
void runDictionary(Dictionary<Key, Value> currentDictionary) {
    cout << "Welcome to your dictionary" << endl;
    printDictionaryMenu();
    char selection = 'A';
    cin >> selection;
    string key;
    KeyValue<Key, Value>* currentIndex;
    while (selection != 'X') {
        switch(selection){
            case 'A':
                handleA(currentDictionary);
                break;
            case 'C':
                cout << "The current key/value count is " << currentDictionary.getCount() << endl;
                break;
            case 'K':
                handleK(currentDictionary);
                break;
            case 'I':
                int index;
                cout << "Enter the index you want to edit: ";
                cin >> index;
                currentIndex = currentDictionary.getByIndex(index);
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
            default:
                cout << "Unknown character. Try again." << endl;
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

void UserInterface::run() {
    string key;
    string value;
    cout << "Welcome to the Dictionary Application" << endl;

    cout << "Enter a key type: ";
    cin >> key;
    cout << endl << "Enter a value type: ";
    cin >> value;
    cout << endl;

    if(key == "string" && value == "string") {
        Dictionary<std::string, std::string> currentDictionary;
    }
    else if (key == "int" && value == "int") {
        Dictionary<int, int> currentDictionary;
    }
    else if (key == "string" && value == "int") {
        Dictionary<std::string, int> currentDictionary;
    }
    else if (key == "int" && value == "string") {
        Dictionary<int, std::string> currentDictionary;
    }

    printMenu();

    char selection = 'A';
    cin >> selection;
    while (selection != 'X') {
        switch(selection) {
            case 'C':
                cout << "Enter a key type: ";
                cin >> key;
                cout << endl << "Enter a value type: ";
                cin >> value;
                cout << endl;

                if(key == "string" && value == "string") {
                    Dictionary<std::string, std::string> currentDictionary;
                }
                else if (key == "int" && value == "int") {
                    Dictionary<int, int> currentDictionary;
                }
                else if (key == "string" && value == "int") {
                    Dictionary<std::string, int> currentDictionary;
                }
                else if (key == "int" && value == "string") {
                    Dictionary<int, std::string> currentDictionary;
                }
                break;
            case 'D':
                //TODO: DELETE DICTIONARY
                break;
            default:
                cout << "Unknown character. Try again." << endl;
                break;
        }
        printMenu();
        cin >> selection;
    }
}
