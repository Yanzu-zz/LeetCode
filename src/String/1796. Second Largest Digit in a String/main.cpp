#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int secondHighest(string s)
  {
    int n = s.size(), mask = 0;

    // 记录下出现的数字
    for (int i = 0; i < n; i++)
    {
      if (s[i] < '0' || s[i] > '9')
        continue;

      mask |= 1 << (s[i] - '0');
    }

    bool isSecondLarge = false;
    for (int i = 9; i >= 0; i--)
    {

      if (mask >> i & 1)
      {
        // 查看是否有第二大的数字
        if (isSecondLarge)
          return i;

        isSecondLarge = true;
      }
    }

    return -1;
  }
};

int main(void)
{

  return 0;
}
