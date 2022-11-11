#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  bool halvesAreAlike(string s)
  {
    int n = s.size();
    int len = n / 2;
    int sum1 = 0, sum2 = 0;
    string key = "aeiouAEIOU";
    // 先对前半段字符串进行查询记录
    for (int i = 0; i < len; i++)
    {
      char ch = s[i];
      int j = 0;
      for (; j < 10 && ch != key[j]; j++)
        ;

      sum1 += (j != 10);
    }

    // 后半段
    for (int i = len; i < n; i++)
    {
      char ch = s[i];
      int j = 0;
      for (; j < 10 && ch != key[j]; j++)
        ;

      sum2 += (j != 10);
    }

    return sum1 == sum2;
  }
};

int main(void)
{

  return 0;
}
