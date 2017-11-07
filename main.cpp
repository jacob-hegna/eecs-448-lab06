/**
*	@author 
*	@date 
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
#include "LinkedListOfInts.h"

#include "Test.hpp"

template<typename T>
bool assert_test(T expect, T actual, std::string test, std::string desc = "") {
    if(expect == actual) {
        std::cout << "Test [" << test << "] passed! Description: " << desc << std::endl;
        return true;
    } else {
        std::cout << "Test [" << test << "] failed! Expected (" << expect << ") but given (" << actual << "). Description: " << desc << std::endl;
        return false;
    }
}

bool test_isEmpty_empty() {
    LinkedListOfInts list;

    auto list_vec = list.toVector();
    assert_test(list_vec.empty(), true, "isEmpty");

    return true;
}

bool test_isEmpty_populated() {
    LinkedListOfInts list;

    for(int i = 0; i < 17; ++i) {
        list.addBack(17);
    }

    auto list_vec = list.toVector();
    if(!list_vec.empty()) {
        std::cout << "Test [isEmpty] failed! The list wasn't empty, but said it was" << std::endl;
        return false;
    }

    return true;
}

int main(int argc, char** argv)
{

}

