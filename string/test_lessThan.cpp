#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
{
  // Test
  String str = "abcd";
  String str2 = "bdefgh";

  // Verify
  assert(str < str2);
}

{
  // Test
  String str = "abcdkjasdhasjhdhj";
  String str2 = "bdefghdslkadlkjkskdjhaskdhhjkdskahdkja";

  // Verify
  assert(str < str2);
}

{
  // Test
  char ch = 'a';
  String str2 = "bdefghdslkadlkjkskdjhaskdhhjkdskahdkja";

  // Verify
  assert(ch < str2);
}

{
  // Test
  char ch[] = "jkahbdjhhkasdh";
  String str2 = "zzzzzzzzfghdslkadlkjkskdjhaskdhhjkdskahdkja";

  // Verify
  assert(ch < str2);
}


  std::cout << "Done testing less than." << std::endl;
}
