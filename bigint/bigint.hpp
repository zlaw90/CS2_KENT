  //Zachary Law
//Big Int Project
//CS 23001
//A program to take in numbers that might be larger than the standard
//64 bit word.

#ifndef bigint_hpp
#define bigint_hpp

#include <iostream>
const int CAPACITY = 400;

class bigint
{

public:

  bigint(); //default constructor
  bigint(int); //int constructor
  bigint(const char[]); //declared bigint testInt = ("98394279109238109381");
  void debugPrint(std::ostream&) const;
  bool operator==(bigint);
  friend std::ostream& operator<<(std::ostream&, const bigint&);
  friend std::istream& operator>>(std::istream&, bigint&);
  bigint operator+(const bigint&) const;
  int operator[](int);  //return the n'th 10's place
  bigint times_digit(int) const;
  bigint times_10(int) const;
  bigint operator*(const bigint&) const;

private:

  int bigIntArray[CAPACITY];
};

//92873498237948723;

#endif
