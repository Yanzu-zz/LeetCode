#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution9
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
      return false;

    stack<int> stk;
    int tmp = x;

    // 将x的每一位存入栈中
    while (tmp > 0)
    {
      stk.push(tmp % 10);
      tmp /= 10;
    }

    // 开始对比
    tmp = x;
    while (tmp > 0)
    {
      if (tmp % 10 != stk.top())
        return false;

      tmp /= 10;
      stk.pop();
    }

    return true;
  }
};

int main()
{

  return 0;
}