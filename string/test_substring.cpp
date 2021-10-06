#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
{
  // Test
  String str = "abcdefghijklmnop";
  String subStr;
  int start = 1;
  int end = 6;

  // Verify
  assert((subStr = str.substr(start, end)) == "bcdefg");

}
  std::cout << "Done testing sub string." << std::endl;
}
