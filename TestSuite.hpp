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
        success &= t_isEmpty_addBack_removeBack();
        success &= t_isEmpty_addBack_removeFront();
        success &= t_isEmpty_addFront_removeBack();
        success &= t_isEmpty_addFront_removeFront();

        // testing function size
        success &= t_size_empty();
        success &= t_size_addBack();
        success &= t_size_addFront();

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

    bool t_isEmpty_addBack_removeBack() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addBack(i);
        }

        for(int i = 0; i < 17; ++i) {
            list.removeBack();
        }

        return assert_test(list.isEmpty(), true, "isEmpty", "pushes to list with addBack then pops with removeBack then calls isEmpty");
    }

    bool t_isEmpty_addBack_removeFront() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addBack(i);
        }

        for(int i = 0; i < 17; ++i) {
            list.removeFront();
        }

        return assert_test(list.isEmpty(), true, "isEmpty", "pushes to list with addBack then pops with removeFront then calls isEmpty");
    }

    bool t_isEmpty_addFront_removeBack() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addFront(i);
        }

        for(int i = 0; i < 17; ++i) {
            list.removeBack();
        }

        return assert_test(list.isEmpty(), true, "isEmpty", "pushes to list with addFront then pops with removeBack then calls isEmpty");
    }

    bool t_isEmpty_addFront_removeBack() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addFront(i);
        }

        for(int i = 0; i < 17; ++i) {
            list.removeFront();
        }

        return assert_test(list.isEmpty(), true, "isEmpty", "pushes to list with addFront then pops with removeFront then calls isEmpty");
    }

    bool t_size_empty() {
        LinkedListOfInts list;

        return assert_test(list.size(), 0, "size", "calls size on a fresh list");
    }

    bool t_size_addBack() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addBack(i);
        }

        return assert_test(list.size(), 17, "size", "pushes to list with addBack then calls size");
    }

    bool t_size_addFront() {
        LinkedListOfInts list;

        for(int i = 0; i < 17; ++i) {
            list.addFront(i);
        }

        return assert_test(list.size(), 17, "size", "pushes to list with addFront then calls size");
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
