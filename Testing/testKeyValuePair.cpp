//
// Created by Makenzie Larsen on 4/5/17.
//

#include <iostream>
#include <string>
#include "testKeyValue.h"

using namespace std;

void testConstructors() {
    cout << "Testing Constructors." << endl;
    KeyValue<string, string> keyValue;
    TEST(keyValue.getKey(), NAN);
    TEST(keyValue.getValue(), NAN);
    KeyValue<string, string> keyValue1("dog", "woof");
    TEST(keyValue1.getKey(), "dog");
    TEST(keyValue1.getValue(), "woof");
    KeyValue<int, int> keyValue2(1, 2);
    TEST(keyValue2.getKey(), 1);
    TEST(keyValue2.getValue(), 2);
    KeyValue<int, int> keyValue3(keyValue2);
    TEST(keyValue3.getKey(), 1);
    TEST(keyValue3.getValue(), 2);
    KeyValue<string, string> keyValue4(keyValue1);
    TEST(keyValue4.getKey(), "dog");
    TEST(keyValue4.getValue(), "woof");
}

void KeyValuePairTester::runTests() {
    testConstructors();
}
