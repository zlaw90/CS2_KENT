#include <iostream>
#include <fstream>
#include <cassert>
#include "string.hpp"



int main()
{
  // Setup
  {
    std::ifstream in("file.txt");    // Define stream for input
    if(!in)
    {                           // Make sure it opened correctly.
        std::cerr << "Could not open file.txt, exiting." << std::endl;
        exit(1);
    }
  // Test
    String str;

    in >> str;

    assert(str == "hellofools");

    in.close();
 }
 std::cout << "Done testing input operator." << std::endl;
}
