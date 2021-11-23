#include <iostream>
#include <vector>

using namespace std;

class Solution859
{
public:
  bool buddyStrings(string s, string goal)
  {
    int n = s.size(), m = goal.size();
    if (n != m)
      return false;

    int aCnt[26] = {0}, bCnt[26] = {0};
    int sum = 0;

    // 统计词频以及位置不同的字母的个数
    for (int i = 0; i < n; i++)
    {
      int a = s[i] - 'a';
      int b = goal[i] - 'a';

      aCnt[a]++;
      bCnt[b]++;

      if (a != b)
        sum++;
    }

    // 下面就是验证是否可以通过一次交换使得两个字符串相等了
    bool isValid = false;
    for (int i = 0; i < 26; i++)
    {
      if (aCnt[i] != bCnt[i])
        return false;
      if (aCnt[i] > 1) // 这里是判断两个字符串相等的情况且有字符重复，这样交换这两个重复字符就可以完成相等
        isValid = true;
    }

    return sum == 2 || (sum == 0 && isValid);
  }
};

int main()
{

  return 0;
}