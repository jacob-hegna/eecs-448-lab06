/**
 * @author: jacob hegna 
 * @date: 11/6/17
 * @file TestSuite.hpp
 * @brief Test class for LinkedListOfInts
 */

#include <algorithm>
#include <iostream>
#include "LinkedListOfInts.h"

/**
 * TestSuite
 * @desc: test class which encapsulates all the tests for lab06
 * @apology: this code could be made significantly cleaner, but ~~~I don't care~~~
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
        success &= t_size_addBack_removeBack();
        success &= t_size_addBack_removeFront();
        success &= t_size_addFront_removeBack();
        success &= t_size_addFront_removeFront();

        // testing function search
        success &= t_search_in();
        success &= t_search_out();

        return success;
    } // end of test_all

    /****
     * Tests below
     * naming convection is:
     *      t_[function to test]_[other functions used in the test]
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

    bool t_isEmpty_addFront_removeFront() {
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

    bool t_size_addBack_removeBack() {
        LinkedListOfInts list;

        int a = 49,
            b = 48;

        for(int i = 0; i < a; ++i) {
            list.addBack(i);
        }

        for(int i = 0; i < b; ++i) {
            list.removeBack();
        }

        return assert_test(list.size(), a-b, "size", "pushes to list with addBack then pops with removeBack then calls size");
    }

    bool t_size_addBack_removeFront() {
        LinkedListOfInts list;

        int a = 100,
            b = 32;

        for(int i = 0; i < a; ++i) {
            list.addBack(i);
        }

        for(int i = 0; i < b; ++i) {
            list.removeFront();
        }

        return assert_test(list.size(), a-b, "size", "pushes to list with addBack then pops with removeFront then calls size");
    }

    bool t_size_addFront_removeBack() {
        LinkedListOfInts list;

        int a = 11,
            b = 9;

        for(int i = 0; i < a; ++i) {
            list.addFront(i);
        }

        for(int i = 0; i < b; ++i) {
            list.removeBack();
        }

        return assert_test(list.size(), a-b, "size", "pushes to list with addFront then pops with removeBack then calls size");
    }

    bool t_size_addFront_removeFront() {
        LinkedListOfInts list;

        int a = 200,
            b = 10;

        for(int i = 0; i < a; ++i) {
            list.addFront(i);
        }

        for(int i = 0; i < b; ++i) {
            list.removeFront();
        }

        return assert_test(list.size(), a-b, "size", "pushes to list with addFront then pops with removeFront then calls size");
    }

    bool t_search_in() {
        LinkedListOfInts list;

        for(int i = 0; i < 20; ++i) {
            list.addFront(i);
        }

        return assert_test(list.search(17), true, "search", "searches the list for a value inside the list");
    }


    bool t_search_out() {
        LinkedListOfInts list;

        for(int i = 0; i < 10; ++i) {
            list.addFront(i);
        }

        return assert_test(list.search(17), false, "search", "searches the list for a value not in the list");
    }

    bool t_addBack() {
        LinkedListOfInts list;
        std::vector<int> vec;

        for(int i = 0; i < 37; ++i) {
            list.addBack(10 - i);
            vec.push_back(10 - i);
        }

        return assert_test(list.toVector() == vec, true, "addBack", "pushes elements to the list with pushBack and compares it to an equivalent vector");
    }

    bool t_addFront() {
        LinkedListOfInts list;
        std::vector<int> vec;

        for(int i = 0; i < 39; ++i) {
            list.addFront(10 - i);
            vec.push_back(10 - i);
        }

        // we pushed elements at the end of the vector, so flip it
        std::reverse(vec.begin(), vec.end());

        return assert_test(list.toVector() == vec, true, "addBack", "pushes elements to the list with pushBack and compares it to an equivalent vector");
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
