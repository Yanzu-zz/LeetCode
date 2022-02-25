#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
private:
  stack<int> stk;    // 主栈
  stack<int> minStk; // 存储当前位置栈中最小值

public:
  MinStack()
  {
  }

  void push(int val)
  {
    stk.push(val);
    if (minStk.empty())
      minStk.push(val);
    else
      minStk.push(val < minStk.top() ? val : minStk.top());
  }

  void pop()
  {
    if (!stk.empty())
    {
      stk.pop();
      minStk.pop(); // stk 不为空则 minStk 也不可能为空
    }
  }

  int top()
  {
    return stk.top();
  }

  int getMin()
  {
    return minStk.top();
  }
};

int main(void)
{

  return 0;
}
