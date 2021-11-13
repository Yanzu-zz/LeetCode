#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution9_2
{
public:
  bool isPalindrome(int x)
  {
    string FW = to_string(x); // forward direction
    string BW = FW;           // backword direction
    reverse(BW.begin(), BW.end()); // reverse string

    return FW == BW;
  }
};

int main()
{

  return 0;
}