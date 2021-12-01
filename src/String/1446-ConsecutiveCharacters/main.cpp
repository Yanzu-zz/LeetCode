#include <iostream>
#include <vector>

using namespace std;

class Solution1446
{
public:
  int maxPower(string s)
  {
    int n = s.size();
    s += " ";

    int counter = 1, res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      // 只要一遇到不同的字符，就计算当前相同字符串长度，并且初始化 counter
      if (s[i] != s[i + 1])
      {
        res = max(res, counter);
        counter = 1;
      }
      else
      {
        counter++;
      }
    }

    return res;
  }
};

int main()
{

  return 0;
}