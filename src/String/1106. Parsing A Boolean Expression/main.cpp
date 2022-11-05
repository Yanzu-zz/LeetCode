#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  bool parseBoolExpr(string expression)
  {
    stack<char> stk;
    int n = expression.size();

    for (char ch : expression)
    {
      // 如果是 , 则跳过
      if (ch == ',')
      {
        continue;
      }
      // 如果不为右括号，则进栈
      else if (ch != ')')
      {
        stk.emplace(ch);
      }
      // 否则就要处理当前这个左右括号的内容了
      else
      {
        int t = 0, f = 0; // true 和 false 的数量
        // 只要没到对应的左括号，就记录数量
        while (stk.top() != '(')
        {
          char curr = stk.top();
          stk.pop();
          if (curr == 't')
            t++;
          else
            f++;
        }
        stk.pop(); // 把对应的左括号出栈

        char op = stk.top(); // 获取操作符
        stk.pop();
        // 根据对应的操作符，有不同的结果
        switch (op)
        {
        case '!':
          stk.push(f == 1 ? 't' : 'f');
          break;
        case '&':
          stk.push(f == 0 ? 't' : 'f');
          break;
        case '|':
          stk.push(t > 0 ? 't' : 'f');
        default:
          break;
        }
      }
    }

    // 处理到最后，肯定是有个结果的
    return stk.top() == 't';
  }
};

int main(void)
{

  return 0;
}
