/**
 * @author: jacob hegna 
 * @date: 11/6/17
 * @file TestSuite.hpp
 * @brief Test class for LinkedListOfInts
 */

#include <iostream>
#include "LinkedListOfInts.h"

/**
 * TestSuite
 * @desc: test class which encapsulates all the tests for lab06
 */
class TestSuite {
public:
    TestSuite() {}
    virtual ~TestSuite() {}

    /**
     * test_all
     * @pre: nothing
     * @post: nothing
     * @return: true if every test returns true
     * @desc: runs all the tests
     */
    bool test_all() {
        bool success = true;

        // testing function isEmpty
        success &= t_isEmpty_empty();
        success &= t_isEmpty_addBack();
        success &= t_isEmpty_addFront();

        return success;
    } // end of test_all

    /****
     * Tests below
     ***/

    bool t_isEmpty_empty() {
        LinkedListOfInts list;

        return assert_test(list.isEmpty(), true, "isEmpty", "calls isEmpty on a fresh list");
    }

    bool t_isEmpty_addBack() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addBack(i);
        }

        return assert_test(list.isEmpty(), false, "isEmpty", "pushes to list with addBack then calls isEmpty");
    }

    bool t_isEmpty_addFront() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addFront(i);
        }

        return assert_test(list.isEmpty(), false, "isEmpty", "pushes to list with addFront then calls isEmpty");
    }

    bool t_size_empty() {
        LinkedListOfInts list;

        return assert_test(list.size(), 0, "size", "calls size on a fresh list");
    }

private: 

    /**
     * assert_test
     * @pre: nothing
     * @post: nothing
     * @return: true if actual == expect
     * @desc: assert, but doesn't halt execution or throw an exception if the assert fails
     */
    template<typename T>
    bool assert_test(T actual, T expect, std::string test, std::string desc = "") {
        if(expect == actual) {
            std::cout << "[" << test << "]: Test \x1b[32mpassed\x1b[0m! Description: " << desc << std::endl;
            return true;
        } else {
            std::cout << "[" << test << "]: Test \x1b[31mfailed\x1b[0m! Expected (" << expect << ") but given (" << actual << "). Description: " << desc << std::endl;
            return false;
        }
    } // end of assert_test

}; // end of class TestSuite
