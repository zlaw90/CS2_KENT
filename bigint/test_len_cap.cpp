#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
{
    // Test
  String str;

  // Verify
  assert(str.length() == 0);
  assert(str.capacity() == 255);
}

{
  // Test
  String str = "abcdefhgivnfhrywusig";

  // Verify
  assert(str.length() == 20);
  assert(str.capacity() == 255);
}

{
  // Test
  String str = 'a';

  // Verify
  assert(str.length() == 1);
  assert(str.capacity() == 255);
}

{
  // Test
  String str = "1234567890abcdefhijkmnbvcx23hg3rdsthfxb4";

  // Verify
  assert(str.length() == 40);
  assert(str.capacity() == 255);
}

  std::cout << "Done testing length and capacity." << std::endl;
}
