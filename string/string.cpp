#include "string.hpp"
#include <cassert>

String::String()
{
  stringSize = 1;
  str = new char[stringSize];
  str[0] = 0;
}

String::String(char ch)
{
  stringSize = 2;
  str = new char[stringSize];
  str[0] = ch;
  str[1] = 0;
}

String::String (const char ch[])
{
  int  count = 0;
  while(ch[count] != 0)
  {
    ++count;
  }

  stringSize = count + 1;
  str = new char[stringSize];

  for(int i = 0; i < stringSize; ++i){ str[i] = ch[i]; }
  str[stringSize - 1] = 0;
}

String::String(int size)
{
  stringSize = size + 1;
  str = new char[stringSize];
  str[stringSize] = 0;
}

String::String(int size, const char ch[])
{
  int count = 0;
  while(ch[count] != 0) ++count;
  if(size < count) size = count;
  stringSize = size + 1;

  str = new char[stringSize];
  for(int i = 0; i < stringSize; ++i)
  {
    str[i] = ch[i];
  }
  str[stringSize] = 0;
}

void String::resetCapacity(int size)
{
  if(size < length()) std::cout << "Cannot reduce size past contents return" << '\n';
  char *temp = new char[size];
  for(int i = 0; i <= length(); ++i){ temp[i] = str[i]; }
  delete[] str;

  stringSize = size;
  str = new char[stringSize];

  for(int i = 0; i <= length(); ++i ){ str[i] = temp[i]; }
  delete[] temp;
}

String::String(const String& actual)
{
  stringSize = actual.stringSize;
  str = new char[stringSize];

  for(int i = 0; i < stringSize; ++i){ str[i] = actual.str[i]; }
  str[stringSize - 1] = 0;
}

String::~String() { if(str != nullptr) delete[] str; }

void String::swap(String& rhs)
{
  int tempSize = stringSize;
  stringSize = rhs.stringSize;
  rhs.stringSize = tempSize;

  char *temp = str;
  str = rhs.str;
  rhs.str = temp;

}

int String::convToInt() const
{
  int converted = 0;
  int endConvert = 0;

  for(int i = 0; i < length(); ++i)
  {
    if(!isdigit(str[length() - 1 - i]))
    {
      continue;
    }
    converted = converted + (str[length() - 1 - i] - 48);
    for(int j = 0; j < i; ++j)
    {
      converted = converted * 10;
    }
    endConvert += converted;
    converted = 0;
  }

  return endConvert;
}

char& String::operator[](int n) { return str[n]; }
char  String::operator[](int n) const { return str[n]; }

int   String::capacity() const{ return stringSize - 1; }

int   String::length  () const
{
  int count = 0;
  while(str[count] != 0)
  {
    ++count;
  }
  return count;
}

String String::operator+(const String& str2) const
{
  String tempStr(str);

  tempStr.resetCapacity(capacity() + str2.capacity() + 1);

  int offset = capacity(); // "= result.length()"
  int i = 0;

  while (str2.str[i] != 0)
  {
    tempStr.str[offset + i] = str2.str[i];
    ++i;
    //Error control i.e. a.length + b.length > capacity
    if ((offset + i) == capacity()) break;
  }

  tempStr.str[offset + i] = 0;
  return tempStr;
 }

String& String::operator+=(const String& str2)
{
  *this = *this + str2;
  return *this;
}

bool String::operator==(const String& rhs) const
{
  int i = 0;
  while ((str[i] != 0) && (str[i] == rhs.str[i])) ++i;
  return str[i] == rhs.str[i];
}

bool String::operator<(const String& str2) const
{
  int index = 0;
  int size = (length() < str2.length() ? length() : str2.length());
  while(str[index] == str2.str[index] && index < size){ ++index; }

  return str[index] < str2.str[index];
}

std::istream& operator>>(std::istream& in, String& newString)
{
  char temp[256];
  in >> temp;
  int count = 0;
  while(temp[count] != 0) ++count;

  delete[] newString.str;

  newString.stringSize = count;
  newString.str = new char[newString.stringSize];

  for(int i = 0; i < newString.stringSize; ++i ){ newString.str[i] = temp[i]; }

  newString.str[newString.stringSize] = 0;
  return in;
}

std::ostream& operator<<(std::ostream& out, const String& stringOut)
{
  for(int i=0; i < stringOut.length(); ++i ){ out << stringOut[i]; }
  return out;
}

String String::getLine(std::istream& input)
{
  String tmp;
  char index;
  input.get(index);

  while(index != '\n' && !input.eof())
  {
    tmp += index;
    input.get(index);
  }
  return tmp;
}

String toString(int num)
{
  char ch;
  String newString;
  int tenPlc;
  if(num==0){return newString = '0';}

  while(num != 0)
  {
    tenPlc = num % 10;
    ch = tenPlc + '0';
    newString = String(ch) + newString;
    num = num / 10;
  }
  return newString;
}

int String::findch(int start, char ch) const
{
  if ( (start < 0) || (start >= length()) ) return -1;
  int i = start;
  while (str[i] != 0)
  {
    if (str[i] == ch) return i;
    ++i;
  }
  return -1;
}

int String::findstr(int start, const String& str2) const
{
  if (start < 0) start = 0;
  if (start > length()) start = length();

  while (start <= length() - str2.length())
  {
    if (substr(start, start + str2.length() - 1) == str2) return start;
    ++start;
  }
  return -1;
}

String String::substr(int start, int end) const
{
  if (start < 0) start = 0;;
  if (start > end) return "";
  if (end > length()) return *this;;

  String result;
  int i = start;
  while (i <= end)
  {
    result += str[i];
    ++i;
  }
  return result;
}

std::vector<String> String::split (char ch) const
{
  std::vector<String> stringSplit;
  int front = 0;
  int back = 0;
  while(back != -1)
  {
    back = findch(front, ch);

    if(back == -1) break;
    if(back == front)
    {
      stringSplit.push_back("");
      front = back + 1;
      continue;
    }

    stringSplit.push_back(substr(front, back - 1));
    front = back + 1;
  }
  if(length() == 1 && str[0] != ch){ stringSplit.push_back(substr(0,0)); }
  else if(front != length()){ stringSplit.push_back(substr(front, length() - 1)); }
  else if(front == length()) { stringSplit.push_back(""); }
return stringSplit;
}

String& String::operator=(String str2)
{
  swap(str2);
  return *this;
}

String  operator+       (const char ch[],  const String& str)
{ return String(ch) + str; }
String  operator+       (char ch,          const String& str)
{ return String(ch) + str; }

bool    operator==      (const char ch[],  const String& str)
{
  if(String(ch) == str) return true;
  else return false;
}
bool    operator==      (char ch,          const String& str)
{
  if(String(ch) == str) return true;
  else return false;
}

bool    operator<       (const char ch[],  const String& str)
{
  if(String(ch) < str) return true;
  else return false;
}
bool    operator<       (char ch,          const String& str)
{
  if(String(ch) < str) return true;
  else return false;
}

bool    operator<=      (const String& str, const String& str2)
{
  if(str < str2 || str == str2) return true;
  else return false;
}
bool    operator!=      (const String& str, const String& str2)
{
  if(!(str == str2)) return true;
  else return false;
}
bool    operator>=      (const String& str, const String& str2)
{
  if(str2 < str || str == str2) return true;
  else return false;
}
bool    operator>       (const String& str, const String& str2)
{
  if(str2 < str) return true;
  else return false;
}
