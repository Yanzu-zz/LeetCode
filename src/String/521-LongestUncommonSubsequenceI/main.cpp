#include <iostream>
#include <vector>

using namespace std;

class Solution521
{
public:
  int findLUSlength(string a, string b)
  {
    return a != b ? max(a.size(), b.size()) : -1;
  }
};

int main(void)
{

  return 0;
}
