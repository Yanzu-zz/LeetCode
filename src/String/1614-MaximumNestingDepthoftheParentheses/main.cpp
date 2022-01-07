#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  int maxDepth(string s)
  {
    int n = s.size();
    int parentheCnt = 0; // 模拟栈
    int res = 0;

    for (const auto &ch : s)
    {
      // 按笔记上的步骤来即可
      if (ch == '(')
      {
        parentheCnt++;
        res = max(res, parentheCnt);
      }
      else if (ch == ')')
      {
        parentheCnt--;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
