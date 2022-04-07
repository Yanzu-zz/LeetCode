#include <iostream>
#include <vector>

using namespace std;

class Solution796_2
{
public:
  bool rotateString(string s, string goal)
  {
    // 将问题转为搜索子串
    return s.size() == goal.size() && (s + s).find(goal) != -1;
  }
};

int main(void)
{

  return 0;
}
