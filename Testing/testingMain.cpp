#include <iostream>
#include "testKeyValue.h"
#include "testDictionary.h"

int main() {

    KeyValuePairTester keyValuePairTester;
    keyValuePairTester.runTests();

    DictionaryTester dictionaryTester;
    dictionaryTester.runTests();

    return 0;
}