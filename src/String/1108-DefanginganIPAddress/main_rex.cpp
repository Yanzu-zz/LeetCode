#include <iostream>
#include <vector>
#include <regex>

using namespace std;

// 正则
regex re("\\.");

class Solution1108
{
public:
  string defangIPaddr(string address)
  {
    return regex_replace(address, re, "[.]");
  }
};

int main()
{

  return 0;
}