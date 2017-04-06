//
// Created by Makenzie Larsen on 4/5/17.
//

#ifndef HW6_PASSFAILMACRO_H
#define HW6_PASSFAILMACRO_H

#define TEST(actual, expected) if (actual == expected) { std::cout << "\033[1;32m PASS \033[0m" << __FUNCTION__ << std::endl;} else { std::cout << "\033[1;31m FAIL \033[0m" << __FUNCTION__ << ": Expected " << expected << ", got " << actual << std::endl; }

#define TEST_NOT(actual, expected) if (actual != expected) { std::cout << "\033[1;32m PASS \033[0m" << __FUNCTION__ << std::endl;} else { std::cout << "\033[1;31m FAIL \033[0m" << __FUNCTION__ << ": Expected not " << expected << ", got " << actual << std::endl; }

#define TEST_NULL(actual) if (actual == nullptr) { std::cout << "\033[1;32m PASS \033[0m" << __FUNCTION__ << std::endl;} else { std::cout << "\033[1;31m FAIL \033[0m" << __FUNCTION__ << ": Expected nullptr" << std::endl; }

#define TEST_NOT_NULL(actual) if (actual != nullptr) { std::cout << "\033[1;32m PASS \033[0m" << __FUNCTION__ << std::endl;} else { std::cout << "\033[1;31m FAIL \033[0m" << __FUNCTION__ << ": Expected not nullptr" << std::endl; }

#endif //HW6_PASSFAILMACRO_H
