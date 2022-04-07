#include <iostream>
#include <vector>

using namespace std;

class Solution796
{
public:
  bool rotateString(string s, string goal)
  {
    int n = s.size();

    if (goal.size() != n)
      return false;

    // 暴力对比
    for (int i = 0; i < n; i++)
    {
      int j = 0;
      for (; j < n; j++)
        if (s[(i + j) % n] != goal[j])
          break;

      // 如果每个元素都对上了
      if (j == n)
        return true;
    }

    return false;
  }
};

int main(void)
{

  return 0;
}
