#ifndef __TEST_HPP_
#define __TEST_HPP_

#include <functional>
#include <iostream>
#include <string>

/**
 * Test
 * a functor which runs a given test
 */
class Test {
public:
    Test
        (
        std::string& aName,
        std::string& aDescription,
        std::function<bool()> aMethod
        )
        : mName(aName)
        , mDescription(aDescription)
        , mMethod(aMethod)
        {}

    
    bool operator()() {
        bool pass = mMethod();
        if(!pass) {
            std::cout << "Test [" << mName << "] failed!" << std::endl; 
        }
        return pass;
    }

private:
    std::string           mName;
    std::string           mDescription;
    std::function<bool()> mMethod;
}; // end of class Test

#endif