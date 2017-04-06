//
// Created by Makenzie Larsen on 4/5/17.
//

#include <iostream>
#include <string>
#include "testKeyValue.h"

using namespace std;

void testConstructorsAndGetters() {
    cout << "Testing Constructors." << endl;

    KeyValue<string, string> keyValue1("dog", "woof");
    if (keyValue1.getKey() != "dog") {
        cout << "Failed string constructor. Expected 'dog'. Got " << keyValue1.getKey() << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (keyValue1.getValue() != "woof") {
        cout << "Failed string constructor. Expected 'woof'. Got " << keyValue1.getValue() << endl;
    } else {
        cout << "Passed." << endl;
    }

    KeyValue<int, int> keyValue2(1, 2);
    if (keyValue2.getKey() != 1) {
        cout << "Failed integer constructor. Expected 1. Got " << keyValue2.getKey() << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (keyValue2.getValue() != 2) {
        cout << "Failed integer constructor. Expected 2. Got " << keyValue2.getValue() << endl;
    } else {
        cout << "Passed." << endl;
    }

    KeyValue<string, string> keyValue3(keyValue1);
    if (keyValue3.getKey() != "dog") {
        cout << "Failed copy string constructor. Expected 'dog'. Got " << keyValue3.getKey() << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (keyValue3.getValue() != "woof") {
        cout << "Failed copy string constructor. Expected 'woof'. Got " << keyValue3.getValue() << endl;
    } else {
        cout << "Passed." << endl;
    }

    KeyValue<int, int> keyValue4(keyValue2);
    if (keyValue4.getKey() != 1) {
        cout << "Failed copy integer constructor. Expected 1. Got " << keyValue4.getKey();
    } else {
        cout << "Passed." << endl;
    }
    if (keyValue4.getValue() != 2) {
        cout << "Failed copy integer constructor. Expected 2. Got " << keyValue4.getValue();
    } else {
        cout << "Passed." << endl;
    }
    cout << "Done testing Constructors." << endl;
}

void KeyValuePairTester::runTests() {
    testConstructorsAndGetters();
}
