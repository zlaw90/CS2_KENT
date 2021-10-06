#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
{
  // Test
  String str = "abcdefghijklmnop";
  char ch = 'j';
  int pos = 0;
  // Verify
  assert(str.findch(pos, ch) == 9);
}

{
  // Test
  String str = "abcdefghijklmnop";
  char ch = 'p';
  int pos = 2;
  // Verify
  assert(str.findch(pos, ch) == 15);
}

{
  // Test
  String str = "abcdefghijklmnop";
  char ch = 'a';
  int pos = 5;
  // Verify
  assert(str.findch(pos, ch) == -1);
}


  std::cout << "Done testing find character." << std::endl;
}
