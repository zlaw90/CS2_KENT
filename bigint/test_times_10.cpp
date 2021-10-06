// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.times_10(0); //test return false digit and no change to bigint

        // Verify
        assert(bi == 3);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.times_10(10);

        // Verify
        assert(bi == "30000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(7);

        // Test
        bi = bi.times_10(7);

        // Verify
        assert(bi == 70000000);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(231);

        // Test
        bi = bi.times_10(9);

        // Verify
        assert(bi == "231000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("5959595959");

        // Test
        bi = bi.times_10(8);

        // Verify
        assert(bi == "595959595900000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1000);

        // Test
        bi = bi.times_10(5);

        // Verify
        assert(bi == 100000000);
    }
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
}
