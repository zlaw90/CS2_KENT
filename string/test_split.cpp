#include "string.hpp"
#include <cassert>

int main()
{
  {
    String test = "asgdahjskld saks csaa s casccs ca,cmn as";
    std::vector<String> split = test.split(' ');

    assert(split[0] == "asgdahjskld");
    assert(split[1] == "saks");
    assert(split[2] == "csaa");
    assert(split[3] == "s");
    assert(split[4] == "casccs");
    assert(split[5] == "ca,cmn");
    assert(split[6] == "as");

    std::cout << "Done testing split method.";
  }
}
