#include <iostream>
#include "testKeyValue.h"
#include "testDictionary.h"

using namespace std;

int main() {

    cout << "Testing Dictionary Application." << endl;

    KeyValuePairTester keyValuePairTester;
    keyValuePairTester.runTests();
    cout << "Done testing KeyValue Pair" << endl;

    DictionaryTester dictionaryTester;
    dictionaryTester.runTests();

    return 0;
}