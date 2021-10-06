#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  {
  // Setup

  // Test
  String str ("abcdefghijklmknopqrtsuvwxyz");
  String str2(str);
  // Verify

  assert(str2 == str);
  }

  {
  // Setup

  // Test

  String str3 ("jjhjjfgjsdhgfjshgfjhsgdf");
  String str2 (str3);
  String str (str2);
  // Verify

  assert(str2 == str3 && str == str2);
  }

  std::cout << "Done testing copy constructor." << std::endl;
}
