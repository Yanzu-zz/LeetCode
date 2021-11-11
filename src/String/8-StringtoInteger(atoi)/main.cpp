#include <iostream>
#include <vector>

using namespace std;

class Solution8
{
public:
  int myAtoi(string s)
  {
    int n = s.size(), i = 0;
    long res = 0;
    bool isNegative = false; // 记录是否负数，否为正数，正为负数
    // 跳过前面的空格字符
    while (i < n && s[i] == ' ')
      i++;

    // 记录正负数
    if (s[i] == '-')
    {
      isNegative = true;
      i++;
    }
    else if (s[i] == '+')
    {
      i++;
    }
    else if (s[i] < '0' && s[i] > '9')
      return 0;

    // 开始模拟转整数
    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
      // 越界
      if (res > INT_MAX)
        break;

      res = res * 10 + s[i] - '0';
      i++;
    }

    if (res > INT_MAX)
    {
      res = INT_MAX;
      if (isNegative)
        res++;
    }

    if (isNegative)
      res = -res;

    return res;
  }
};

int main()
{
  string s1 = "21474836460";
  cout << Solution8().myAtoi(s1) << endl;

  return 0;
}