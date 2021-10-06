#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup

{// Test
  String str('f');

  // Verify
  assert(str == 'f');
}

{// Test
  String str('2');

  // Verify
  assert(str == '2');
}
  std::cout << "Done testing char constructor." << std::endl;
}
