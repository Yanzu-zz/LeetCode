#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1996
{
public:
  int numberOfWeakCharacters(vector<vector<int>> &properties)
  {
    // 我们按照 攻击大到小，防御小到大 排序
    sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]); });

    int res = 0;
    int maxDef = 0;
    // 这样在遍历时只要判断防御的高低即可（因为前面的一定是比它高攻击的）
    for (auto p : properties)
    {
      if (p[1] < maxDef)
        res++;
      else
        maxDef = p[1];
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
