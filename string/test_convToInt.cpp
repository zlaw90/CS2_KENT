#include "string.hpp"
#include <cassert>

int main()
{
  {
  String s = ("1234");
  int conv = s.convToInt();
  assert(conv == 1234);
  }
  {
  String s = ("123473928");
  int conv = s.convToInt();
  assert(conv == 123473928);
  }
  {
  String s = ("389200942");
  int conv = s.convToInt();
  assert(conv == 389200942);
  }
  {
  String s = (":389200942");
  int conv = s.convToInt();
  assert(conv == 389200942);
  }
  {
  String s = (":389200942");
  int conv = s.convToInt();
  assert(conv == 389200942);
  }
}
