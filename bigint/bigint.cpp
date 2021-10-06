//Zachary Law
//bigint.cpp
//CS 23001
//CPP file for bigint to define the functions of "bigint" class

#include "bigint.hpp"

bigint::bigint() //default constructor setting bigint to "0"
{
  for(int i = 0; i < CAPACITY; ++i)
  {
    bigIntArray[i] = 0;
  }
}

bigint::bigint(int userNumber) : bigint()//say 5341 is passed
{
  int i = 0;
  while(userNumber != 0)
  {
    int tensPlace = userNumber % 10; //first loop pass this equals 1
    userNumber = userNumber / 10; // newBigInt now = 534
    bigIntArray[i] = tensPlace; //index 0 = 1
    ++i; //changes index to 1
  }

}

bigint::bigint(const char num[]) : bigint()
{
  int charConvertKey = 48;
  int arrayCounter = 0;

  while(num[arrayCounter] != '\0')
  {
    ++arrayCounter;
  }

  arrayCounter = arrayCounter - 1;//since the while loop ends one beyond our num

  for(int i = 0; i <= arrayCounter; ++i)
  {
    bigIntArray[i] = num[arrayCounter - i] - charConvertKey;
  }
}

void bigint::debugPrint(std::ostream& out) const
{
  int lineMax = 0;
  for(int i = CAPACITY - 1; i >= 0; --i)
  {
    out << bigIntArray[i] << "|";
    lineMax += 2;
    if(lineMax == 80)
    {
      out << std::endl;
      lineMax = 0;
    }
  }
}

bool bigint::operator==(bigint bigInt2)
{
  bool equalTest = false;
  for(int i = 0; i < CAPACITY; ++i)
  {
    if(bigIntArray[i] != bigInt2.bigIntArray[i])
    {
      return equalTest;
    }
  }
  equalTest = true;
  return equalTest;
}

std::ostream& operator<<(std::ostream& out, const bigint& aBigInt)

{
  bool hitNum = false;
  int maxPerLine = 0;

  for(int i = CAPACITY - 1; i >= 0 ; --i)
  {
    if(hitNum)
    {
      out << aBigInt.bigIntArray[i];
      ++maxPerLine;
      if(maxPerLine == 80)
      {
        out << std::endl;
        maxPerLine = 0;
      }
    }
    else if(aBigInt.bigIntArray[i] != 0)
    {
      hitNum = true;
      out << aBigInt.bigIntArray[i];
      ++maxPerLine;
    }

  }
  if(!hitNum)
  {
    out << aBigInt.bigIntArray[0];
  }

  return out;
}
//------------------------------------------------------------------
int bigint::operator[](int indexNum) //This is my [] operator function
{
  int positionValue=0;
  positionValue = bigIntArray[indexNum];
  return positionValue;
}
//--------------------------------------------------------------
std::istream& operator>>(std::istream& in, bigint& aBigInt)
{
  char ch;
  int arrayCounter = 0;
  char newBigInt[CAPACITY];
  int charConvert = 48;

  in.get(ch);
  while(ch != ';' && !in.eof())
  {
    newBigInt[arrayCounter] = ch;
    ++arrayCounter;
    in.get(ch);
  }

  arrayCounter = arrayCounter-1;

  for(int i = 0; i <= arrayCounter; i++)
  {
    if(isdigit(newBigInt[arrayCounter - i]))
    {
    aBigInt.bigIntArray[i] = newBigInt[arrayCounter - i] - charConvert;
    }
  }
  return in;
}

bigint bigint::operator+(const bigint &bi) const
{
  bigint returnResult = 0;

  for(int i = 0; i < CAPACITY - 2; ++i)
  {
    returnResult.bigIntArray[i] += bigIntArray[i] + bi.bigIntArray[i];

    if(returnResult.bigIntArray[i] >= 10)
    {
      returnResult.bigIntArray[i] = returnResult.bigIntArray[i] % 10;
      returnResult.bigIntArray[i + 1] = returnResult.bigIntArray[i+1] + 1;
    }
  }
  return returnResult;
}

bigint bigint::times_10(int zerosAdded) const
{
  bigint newBigInt;
  if(zerosAdded > 0)
  {
   for(int i = zerosAdded; i < CAPACITY; ++i)
   {
     newBigInt.bigIntArray[i] = bigIntArray[i - zerosAdded];
   }
  }
  else if(zerosAdded <= 0)
  {
  return this;
  }
return newBigInt;
}

bigint bigint::times_digit(int toMultiplyBy) const
{
  bigint newBigInt;
  bigint tempBigInt;
  int carryDigit = 0;
  for (int i = 0; i < CAPACITY - 1; ++i)
  {
    tempBigInt.bigIntArray[0] = toMultiplyBy * bigIntArray[i];
    if(tempBigInt.bigIntArray[0] >= 10)
    {
      carryDigit = tempBigInt.bigIntArray[0] / 10;
      tempBigInt.bigIntArray[0] = tempBigInt.bigIntArray[0] % 10;
      tempBigInt.bigIntArray[1] = tempBigInt.bigIntArray[1] + carryDigit;
    }
    tempBigInt = tempBigInt.times_10(i);
    newBigInt = newBigInt + tempBigInt;

    for(int j=0; j<CAPACITY; ++j)
    {
      tempBigInt.bigIntArray[j] = 0;
    }
  }
  return newBigInt;
}

bigint bigint::operator*(const bigint& bigInt2) const
{
  bigint product = 0;
  bigint temp = 0;
  for(int i = 0; i < CAPACITY - 1; ++i)
  {
    temp = this->times_digit(bigInt2.bigIntArray[i]);
    product = product + temp.times_10(i);
  }

  return product;
}
