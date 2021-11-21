#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution20
{
public:
  bool isValid(string s)
  {
    int n = s.size();

    stack<char> stk;
    for (const auto &ch : s)
    {
      if (ch == '(' || ch == '[' || ch == '{')
        stk.push(ch);
      else
      {
        if (stk.empty())
          return false;
        // 用栈做匹配
        char top = stk.top();
        if (ch == ')' && top != '(' ||
            ch == ']' && top != '[' ||
            ch == '}' && top != '{')
          return false;
        stk.pop();
      }
    }

    // 如果在消除的过程结束后还有残余，那么表示这个括号字符串不能匹配
    return stk.empty();
  }
};

int main()
{

  return 0;
}