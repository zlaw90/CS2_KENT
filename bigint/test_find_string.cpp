#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
{
  // Test
  String str = "abcdefghijklmnop";
  int pos = 0;
  String str2  = "abc";

  // Verify
  assert(str.findStr(pos, str2) == 0);
}

{
  // Test
  String str = "abcdefghijklmnop";
  int pos = 5;
  String str2  = "abc";

  // Verify
  assert(str.findStr(pos, str2) == -1);
}

  std::cout << "Done testing find String." << std::endl;
}
