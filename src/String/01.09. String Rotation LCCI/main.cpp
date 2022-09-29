#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isFlipedString(string s1, string s2)
  {
    if (s1.size() != s2.size())
      return false;

    return (s2 + s2).find(s1) != string::npos;
  }
};

int main(void)
{

  return 0;
}
