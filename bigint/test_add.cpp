// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);

   }

   {

       bigint left(2);
       bigint right(4);
       bigint result;

       // Test
       result = left + right;

       // Verify
       assert(left   == 2);
       assert(right  == 4);
       assert(result == 6);

  }
  {

      bigint left(52);
      bigint right(48);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 52);
      assert(right  == 48);
      assert(result == 100);

 }
 {

     bigint  left("111111111111111111111111111111");
     bigint right("111111111111111111111111111111");
     bigint result;

     // Test
     result = left + right;

     // Verify
     assert(left   == "111111111111111111111111111111");
     assert(right  == "111111111111111111111111111111");
     assert(result == "222222222222222222222222222222");

}
{

     bigint  left("98989898989898989898989898989898");
     bigint right("9999999999999999999999999999999");
     bigint result;

     // Test
     result = left + right;

     // Verify
     assert(left   == "98989898989898989898989898989898");
     assert(right  == "9999999999999999999999999999999");
     assert(result == "108989898989898989898989898989897");

}
{

     bigint  left("6987361983276438916239841629384762983469182376498127364981276398417262928137649872634");
     bigint right("87621398476239847612893746981273649812736498127364987123689476128127369841726398476");
     bigint result;

     // Test
     result = left + right;

     // Verify
     assert(left   == "6987361983276438916239841629384762983469182376498127364981276398417262928137649872634");
     assert(right  == "87621398476239847612893746981273649812736498127364987123689476128127369841726398476");
     assert(result == "7074983381752678763852735376366036633281918874625492352104965874545390297979376271110");

}
{

     bigint  left("54");
     bigint right(100);
     bigint result;

     // Test
     result = left + right;

     // Verify
     assert(left   == "54");
     assert(right  == 100);
     assert(result == 154);

}
{

     bigint  left("984759384659309485348567349");
     bigint right(123928398);
     bigint result;

     // Test
     result = left + right;

     // Verify
     assert(left   == "984759384659309485348567349");
     assert(right  == 123928398);
     assert(result == "984759384659309485472495747");

}





    return 0;
}
