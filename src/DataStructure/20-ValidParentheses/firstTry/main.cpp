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
    if (n <= 1)
      return false;

    stack<char> stk;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
      {
        stk.push(s[i]);
      }
      else // 因为题目指明了非左括号就是右括号，所以这里可以这样写
      {
        if (stk.size() == 0)
          return false;
        char c = stk.top();
        if (s[i] == ')' && c != '(' ||
            s[i] == ']' && c != '[' ||
            s[i] == '}' && c != '{')
          return false;
        stk.pop();
      }
    }

    return stk.size() == 0;
  }
};

int main(void)
{

  return 0;
}
