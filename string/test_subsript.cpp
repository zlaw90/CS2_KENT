#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
{
  // Test
  String str = "abcdefghijklmopqrstuvwxyz";
  char ch[] = "abcdefghijklmopqrstuvwxyz"
  // Verify
  for(int i = 0; i = str.length(); ++i)
  {
    assert(str[i] = ch[i])
  }
}
  std::cout << "Done testing subscript." << std::endl;
}
