#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup

{
  // Test
  String str ("skjhdajkhakjdhabsdjkfhdbkjahs");

  // Verify
  assert(str == "skjhdajkhakjdhabsdjkfhdbkjahs");
}

{
  // Test
  String str ("1234567890abcdefghijklmnopqrstuvwxyz");

  // Verify
  assert(str == "1234567890abcdefghijklmnopqrstuvwxyz");
}

{
  // Test
  String str ("ababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab");

  // Verify
  assert(str == "ababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab");
}

  std::cout << "Done testing character array." << std::endl;
}
