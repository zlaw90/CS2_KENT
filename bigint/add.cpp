//==============================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main()
{
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in)
    {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
    bigint a, b, c;
    int arrayCounter = 0;


    //c = a + b this is the same as
    //c = a.operator+(b)  this
    while(!in.eof())
    {
      in >> a;
      in >> b;

      std::cout << std::endl << "bigint a: " << a << std::endl;
      std::cout << std::endl << "bigint b: " << b << std::endl;;

      c = a + b;

      std::cout << std::endl << "bigint c: "<< c << std::endl;
      a = 0;
      b = 0;
      c = 0;
      ++arrayCounter;
      if(arrayCounter == 3) break;
    }
    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results

    in.close();
    return 0;
}
