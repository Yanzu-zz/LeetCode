#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> buildArray(vector<int> &target, int n)
  {
    vector<string> res;
    int len = target.size();

    int i = 0, curr = 1;
    while (i < len)
    {
      res.emplace_back("Push");
      if (target[i] == curr++)
        i++;
      else
        res.emplace_back("Pop");
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
