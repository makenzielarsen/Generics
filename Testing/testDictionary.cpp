//
// Created by Makenzie Larsen on 4/5/17.
//

#include <iostream>
#include "testDictionary.h"

using namespace std;

void testConstructors() {
    cout << "Testing constructors." << endl;

    Dictionary<string, string> dictionary;
    if (dictionary.getCapacity() != 10) {
        cout << "Failed default constructor. Expected capacity: 10. Actual: " << dictionary.getCapacity() << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (dictionary.getCount() != 0) {
        cout << "Failed default constructor. Expected count: 0. Actual: " << dictionary.getCount() << endl;
    } else {
        cout << "Passed." << endl;
    }

    Dictionary<int, int> dictionary1;
    if (dictionary1.getCapacity() != 10) {
        cout << "Failed default constructor. Expected capacity: 10. Actual: " << dictionary1.getCapacity() << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (dictionary1.getCount() != 0) {
        cout << "Failed default constructor. Expected count: 0. Actual: " << dictionary1.getCount() << endl;
    } else {
        cout << "Passed." << endl;
    }

    Dictionary<string, string> dictionary2(1000);
    if (dictionary2.getCapacity() != 1000) {
        cout << "Failed capacity constructor. Expected capacity: 1000. Actual: " << dictionary2.getCapacity() << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (dictionary2.getCount() != 0) {
        cout << "Failed capacity constructor. Expected count: 0. Actual: " << dictionary2.getCount() << endl;
    } else {
        cout << "Passed." << endl;
    }

    Dictionary<int, int> dictionary3(1000);
    if (dictionary3.getCapacity() != 1000) {
        cout << "Failed capacity constructor. Expected capacity: 1000. Actual: " << dictionary3.getCapacity() << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (dictionary3.getCount() != 0) {
        cout << "Failed capacity constructor. Expected count: 0. Actual: " << dictionary3.getCount() << endl;
    } else {
        cout << "Passed." << endl;
    }

    dictionary2.add("dog", "cat");

    Dictionary<string, string> dictionary4(dictionary2);
    if (dictionary4.getCount() != 1) {
        cout << "Failed capacity constructor. Expected capacity: 1000. Actual: " << dictionary4.getCapacity() << endl;
    } else {
        cout << "Passed." << endl;
    }

    dictionary3.add(1,2);
    dictionary3.add(2,3);
    dictionary3.add(3,4);

    Dictionary<int, int> dictionary5(dictionary3);
    if (dictionary5.getCount() != 3) {
        cout << "Failed capacity constructor. Expected count: 0. Actual: " << dictionary5.getCount() << endl;
    } else {
        cout << "Passed." << endl;
    }
    cout << "Done testing constructors." << endl;
}

void testAddAndEdit() {
    cout << "Testing Add and Edit" << endl;
    Dictionary<string, string> dictionary;
    dictionary.add("yin", "yang");
    if (dictionary.getByIndex(0)->getKey() != "yin" || dictionary.getByKey("yin")->getKey() != "yin") {
        cout << "Failed to add key/value pair." << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (dictionary.getByIndex(0)->getValue() != "yang" || dictionary.getByKey("yin")->getValue() != "yang") {
        cout << "Failed to add key/value pair." << endl;
    } else {
        cout << "Passed." << endl;
    }
    dictionary.edit("yin", "dark-light");
    if (dictionary.getByIndex(0)->getKey() != "yin" || dictionary.getByKey("yin")->getKey() != "yin") {
        cout << "Failed to edit key/value pair." << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (dictionary.getByIndex(0)->getValue() != "dark-light" || dictionary.getByKey("yin")->getValue() != "dark-light") {
        cout << "Failed to edit key/value pair." << endl;
    } else {
        cout << "Passed." << endl;
    }

    Dictionary<int, int> dictionary1;
    dictionary1.add(42, 2017);
    if (dictionary1.getByIndex(0)->getKey() != 42 || dictionary1.getByKey(42)->getKey() != 42) {
        cout << "Failed to add key/value pair." << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (dictionary1.getByIndex(0)->getValue() != 2017 || dictionary1.getByKey(42)->getValue() != 2017) {
        cout << "Failed to add key/value pair." << endl;
    } else {
        cout << "Passed." << endl;
    }
    dictionary1.edit(42, 21);
    if (dictionary1.getByIndex(0)->getKey() != 42 || dictionary1.getByKey(42)->getKey() != 42) {
        cout << "Failed to edit key/value pair." << endl;
    } else {
        cout << "Passed." << endl;
    }
    if (dictionary1.getByIndex(0)->getValue() != 21 || dictionary1.getByKey(42)->getValue() != 21) {
        cout << "Failed to edit key/value pair." << endl;
    } else {
        cout << "Passed." << endl;
    }
    cout << "Done testing Add and Edit" << endl;
}

void testGetters() {
    cout << "Testing Getter functions" << endl;
    Dictionary<string, string> dictionary;
    dictionary.add("Hair color", "Brown");
    dictionary.add("Eye color", "Brown");
    KeyValue<string, string>* keyValue = dictionary.getByIndex(0);
    if (keyValue->getKey() != "Hair color" || keyValue->getValue() != "Brown") {
        cout << "Failed to get by index" << endl;
    } else {
        cout << "Passed." << endl;
    }
    const KeyValue<string, string>* keyValue1 = dictionary.getByKey("Eye color");
    if (keyValue1->getKey() != "Eye color" || keyValue1->getValue() != "Brown") {
        cout << "Failed to get by key" << endl;
    } else {
        cout << "Passed." << endl;
    }
    int index = dictionary.getIndex("Hair color");
    if (index != 0) {
        cout << "Failed to get index" << endl;
    } else {
        cout << "Passed." << endl;
    }

    Dictionary<int, int> dictionary1;
    dictionary1.add(5, 13);
    dictionary1.add(7, 82);
    KeyValue<int, int>* keyValue2 = dictionary1.getByIndex(0);
    if (keyValue2->getKey() != 5 || keyValue2->getValue() != 13) {
        cout << "Failed to get by index" << endl;
    } else {
        cout << "Passed." << endl;
    }
    const KeyValue<int, int>* keyValue3 = dictionary1.getByKey(7);
    if (keyValue3->getKey() != 7 || keyValue3->getValue() != 82) {
        cout << "Failed to get by key" << endl;
    } else {
        cout << "Passed." << endl;
    }
    int index1 = dictionary1.getIndex(5);
    if (index1 != 0) {
        cout << "Failed to get index" << endl;
    } else {
        cout << "Passed." << endl;
    }
    cout << "Done testing Getters" << endl;
}

void testRemoves() {
    cout << "Testing remove functions" << endl;
    Dictionary<string, string> dictionary;
    dictionary.add("silent", "night");
    dictionary.add("bright", "star");
    dictionary.add("solemn", "vow");
    dictionary.add("whiskey", "jar");
    dictionary.removeByIndex(0);
    if (dictionary.getCount() != 3 || dictionary.getByIndex(0)->getKey() != "bright" || dictionary.getByIndex(0)->getValue() != "star") {
        cout << "Failed to remove by index" << endl;
    } else {
        cout << "Passed." << endl;
    }
    dictionary.removeByKey("solemn");
    if (dictionary.getCount() != 2 || dictionary.getByIndex(1)->getKey() != "whiskey" || dictionary.getByIndex(1)->getValue() != "jar") {
        cout << "Failed to remove by index" << endl;
    } else {
        cout << "Passed." << endl;
    }

    Dictionary<int, int> dictionary1;
    dictionary1.add(1, 2);
    dictionary1.add(3, 4);
    dictionary1.add(5, 6);
    dictionary1.add(7, 8);
    dictionary1.removeByIndex(0);
    if (dictionary1.getCount() != 3 || dictionary1.getByIndex(0)->getKey() != 3 || dictionary1.getByIndex(0)->getValue() != 4) {
        cout << "Failed to remove by index" << endl;
    } else {
        cout << "Passed." << endl;
    }
    dictionary1.removeByKey(5);
    if (dictionary1.getCount() != 2 || dictionary1.getByIndex(1)->getKey() != 7 || dictionary1.getByIndex(1)->getValue() != 8) {
        cout << "Failed to remove by index" << endl;
    } else {
        cout << "Passed." << endl;
    }
    cout << "Done testing remove functions" << endl;
}

void DictionaryTester::runTests() {
    cout << "Testing Dictionary" << endl;
    testConstructors();
    testAddAndEdit();
    testGetters();
    testRemoves();
    cout << "Done Testing Dictionary" << endl;
    cout << endl;
}
