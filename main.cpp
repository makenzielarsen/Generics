#include <iostream>
#include <string>
#include "Dictionary.h"

int main() {

    Dictionary<std::string, std::string> myDictionary(1000);

    myDictionary.add("hair color", "brown");

    KeyValue* hairColor = myDictionary.getByKey("hair color");


}