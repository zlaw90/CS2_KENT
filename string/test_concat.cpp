#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
  // Setup
{
  // Test
  String str('a');
  String str2('b');
  String str3;

  str3 = str + str2;

  // Verify
  assert(str3 == "ab");
}

{
  // Test
  String str = "asdasdadaadad";
  String str2 = "kasjhdljaskdjha";
  String str3;

  str3 = str + str2;


  // Verify
  assert(str3 == "asdasdadaadadkasjhdljaskdjha");
}

{
  // Test
  char ch[] = "asdasdadaadadasdasdadaadad";
  String str2 = "kasjhdljaskdjha";
  String str3;

  str3 = ch + str2;


  // Verify
  assert(str3 == "asdasdadaadadasdasdadaadadkasjhdljaskdjha");
}

{
  // Test
  char ch = 'a';
  String str2 = "kasjhdljaskdjha";
  String str3;

  str3 = ch + str2;


  // Verify
  assert(str3 == "akasjhdljaskdjha");
}
  std::cout << "Done testing concat." << std::endl;
}
