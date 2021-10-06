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
  int start = 3;
  int end = 5;
  
  // Verify
  assert((subStr = str.subStr(start, end)) == "def");

}
  std::cout << "Done testing sub string." << std::endl;
}
