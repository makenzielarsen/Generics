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
    cout << "D - Get capacity" << endl;
    cout << "K - Edit by key" << endl;
    cout << "I - Edit by index" << endl;
    cout << "R - Remove by index" << endl;
    cout << "S - Remove by key" << endl;
    cout << "X - Delete dictionary" << endl;
}

template<typename Key, typename Value>
void addKeyValue(Dictionary<Key, Value> &currentDictionary) {
    Key key;
    Value value;
    cout << "Input key: ";
    cin >> key;
    cout << "Input value: ";
    cin >> value;
    currentDictionary.add(key, value);
}

template<typename Key, typename Value>
void editByKey(Dictionary<Key, Value> &dictionary) {
    Key key;
    Value value;
    cout << "Enter the key you want to edit: ";
    cin >> key;

    try {
        const KeyValue<Key, Value>* currentKey = dictionary.getByKey(key);
        cout << "Current Key: " << currentKey->getKey() << endl;
        cout << "Current Value: " << currentKey->getValue() << endl;
        cout << "Enter new value: ";
        cin >> value;
        dictionary.edit(key, value);
        cout << "New Key: " << key << endl;
        cout << "New Value: " << value << endl;
    }
    catch (out_of_range) {
        cout << "Dictionary has no value for key: " << key << endl;
        return;
    }
}

template<typename Key, typename Value>
void editByIndex(Dictionary<Key, Value> &dictionary) {
    int index;
    Key key;
    Value value;
    cout << "Enter the index you want to edit: ";
    cin >> index;

    try{
        KeyValue<Key, Value>* currentIndex = dictionary.getByIndex(index);
        currentIndex ;
        cout << "Current Key: " <<currentIndex->getKey() << endl;
        cout << "Current Value: " << currentIndex->getValue() << endl;
        cout << "Enter new value: ";
        cin >> value;
        dictionary.edit(key, value);
        cout << "New Key: " << key << endl;
        cout << "New Value: " << value << endl;
    } catch (out_of_range){
        cout << "Index not found: " << index << endl;
        return;
    }

};

template<typename Key, typename Value>
void runDictionary(Dictionary<Key, Value> &currentDictionary) {
    cout << "Welcome to your dictionary" << endl;
    printDictionaryMenu();
    char selection = 'A';
    cin >> selection;
    Key key;
    int index;
    while (selection != 'X') {
        switch(selection){
            case 'A':
                addKeyValue(currentDictionary);
                break;
            case 'C':
                cout << "The current key/value count is " << currentDictionary.getCount() << endl;
                break;
            case 'D':
                cout << "Dictionary has capacity of " << currentDictionary.getCapacity() << endl;
                break;
            case 'K':
                editByKey(currentDictionary);
                break;
            case 'I':
                editByIndex(currentDictionary);
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
    cout << "X - Exit Program" << endl;
}

void UserInterface::run() {
    char selection;
    string key;
    string value;

    cout << "Welcome to the Dictionary Application" << endl;

    do {
        printMenu();

        cin >> selection;

        switch (selection) {
            case 'X':
                break;
            case 'C':
                cout << "Enter a key type: ";
                cin >> key;
                cout << endl << "Enter a value type: ";
                cin >> value;
                cout << endl;

                if (key == "string" && value == "string") {
                    Dictionary<std::string, std::string> currentDictionary;
                    runDictionary(currentDictionary);
                } else if (key == "int" && value == "int") {
                    Dictionary<int, int> currentDictionary;
                    runDictionary(currentDictionary);
                } else if (key == "string" && value == "int") {
                    Dictionary<std::string, int> currentDictionary;
                    runDictionary(currentDictionary);
                } else if (key == "int" && value == "string") {
                    Dictionary<int, std::string> currentDictionary;
                    runDictionary(currentDictionary);
                }
                break;
            default:
                cout << "Unknown character. Try again." << endl;
                break;
        }

    } while (selection != 'X');
}
