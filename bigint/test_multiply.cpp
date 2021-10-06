// bigint Test Program
//
// Tests:  multiply, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(1);
        bigint right(0);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   == 1);
        assert(right  == 0);
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(2);
        bigint right(1);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   == 2);
        assert(right  == 1);
        assert(result == 2);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(400);
        bigint right(200);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   == 400);
        assert(right  == 200);
        assert(result == 80000);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(10000);
        bigint right(343434);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   == 10000);
        assert(right  == 343434);
        assert(result == "3434340000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(123456789);
        bigint right(123456789);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   == 123456789);
        assert(right  == 123456789);
        assert(result == "15241578750190521");
        //assert(result == "15241578750190520");
    }



    std::cout << "Done testing multiply" << std::endl;
}
