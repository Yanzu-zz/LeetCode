#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minOperations(string s)
  {
    int cnt = 0, n = s.size();
    // 计算第一个元素为0，后面要翻转多少次
    for (int i = 0; i < n; i++)
    {
      char ch = s[i];
      if (ch != ('0' + i % 2))
        cnt++;
    }

    // 第一个元素为1+第一个元素为0 == n，两者取最小值
    return min(cnt, n - cnt);
  }
};

int main(void)
{

  return 0;
}
