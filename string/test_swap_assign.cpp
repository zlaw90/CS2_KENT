#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup

{
  // Test
  String str ("skjhdajkhakjdhabsdjkfhdbkjahs");
  String str2;

  str2 = str;

  // Verify
  assert(str2 == "skjhdajkhakjdhabsdjkfhdbkjahs");
}

  std::cout << "Done testing swap assign." << std::endl;
}
