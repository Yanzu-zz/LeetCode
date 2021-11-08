#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution739
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> stk; // 注意！栈存的是索引，不是具体的温度值

    for (int i = 0; i < n; i++)
    {
      while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
      {
        int prevTemper = stk.top();
        res[prevTemper] = i - prevTemper;
        stk.pop();
      }
      stk.push(i);
    }

    return res;
  }
};

int main()
{

  return 0;
}