#include <iostream>
#include "testKeyValue.h"
#include "testDictionary.h"

using namespace std;

int main() {

    cout << "Testing Dictionary Application." << endl;
    cout << endl;

    KeyValuePairTester keyValuePairTester;
    keyValuePairTester.runTests();

    DictionaryTester dictionaryTester;
    dictionaryTester.runTests();

    return 0;
}