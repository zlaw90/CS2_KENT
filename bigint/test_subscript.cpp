#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
{
  // Test
  String str = "abcdefghijklmopqrstuvwxyz";

  // Verify
  assert(str[0] == 'a');
  assert(str[8] == 'i');
  assert(str[5] == 'f');
  assert(str[10] == 'k');
  assert(str[13] == 'o');
  assert(str[16] == 'r');
  assert(str[20] == 'v');
  assert(str[24] == 'z');

}
  std::cout << "Done testing subscript." << std::endl;
}
