#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup

  // Test
  String str;

  // Verify
  assert(str == "\0");

  std::cout << "Done testing default constructor." << std::endl;
}
