#include <iostream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
{
  // Test
  String str;
  String str2;

  // Verify
  assert(str == str2);
}

{
  // Test
  String str = 'a';
  String str2 = 'a';

  // Verify
  assert(str == str2);
}

{
  // Test
  String str = "aalksjdlaqkhdaldhaskjldfgldkfhjasf";
  String str2 = "aalksjdlaqkhdaldhaskjldfgldkfhjasf";

  // Verify
  assert(str == str2);


}

{
  // Test
  String str = "asdakjshdkajshd19827ksajdhajs";
  String str2 = "asdakjshdkajshd19827ksajdhajs";

  // Verify
  assert(str == str2);

  std::cout << "Done testing equal." << std::endl;
}

}
