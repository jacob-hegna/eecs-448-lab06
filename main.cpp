/**
*   @author: jacob hegna 
*	@date: 11/6/17
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
#include "LinkedListOfInts.h"

#include "Test.hpp"

template<typename T>
bool assert_test(T actual, T expect, std::string test, std::string desc = "") {
    if(expect == actual) {
        std::cout << "[" << test << "]: Test \x1b[32mpassed\x1b[0m! Description: " << desc << std::endl;
        return true;
    } else {
        std::cout << "[" << test << "]: Test \x1b[31mfailed\x1b[0m! Expected (" << expect << ") but given (" << actual << "). Description: " << desc << std::endl;
        return false;
    }
}

class TestSuite {
public:
    TestSuite() {}

    bool test_all() {
        bool success = true;

        success &= t_isEmpty_empty();
        success &= t_isEmpty_addBack();
        success &= t_isEmpty_addFront();

        return success;
    }

    bool t_isEmpty_empty() {
        LinkedListOfInts list;

        auto list_vec = list.toVector();
        return assert_test(list_vec.empty(), true, "isEmpty", "calls isEmpty on a fresh list");
    }

    bool t_isEmpty_addBack() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addBack(i);
        }

        auto list_vec = list.toVector();
        return assert_test(list_vec.empty(), false, "isEmpty", "pushes to list with addBack then calls isEmpty");
    }

    bool t_isEmpty_addFront() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addFront(i);
        }

        auto list_vec = list.toVector();
        return assert_test(list_vec.empty(), false, "isEmpty", "pushes to list with addFront then calls isEmpty");
    }

};


int main(int argc, char** argv)
{
    TestSuite tests;
    tests.test_all();
    
    return 0;
}

