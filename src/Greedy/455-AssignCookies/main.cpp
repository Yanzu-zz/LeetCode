#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution455
{
public:
  /**
 * 策略：每次都尝试将最大的饼干分发给胃口最大的小朋友，这样下一轮分发时倒数第二个饼干就变成了最大的饼干。
 * 且如果最大的饼干都无法满足胃口最大的孩子，那么就说明我们无法满足这位孩子，
 * 此时我们只能让最大的饼干满足次大胃口的孩子。
 */
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    // 因为题目没说给定的数组是有序的，所以我们需要手动给他排好序
    // 我们这里排为从大到小，这样就能从0开始分发（从小到大也一样，只不过要注意一下索引）
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());

    int si = 0, gi = 0; // 两个数组的游标，si 为饼干游标，gi 为孩子胃口游标
    int res = 0;

    while (gi < g.size() && si < s.size())
    {
      // 如果当前最大的饼干能够满足当前最大胃口的孩子，则分发给他
      if (s[si] >= g[gi])
      {
        res++; // 成功分发一位小朋友
        // 游标继续往后
        si++;
        gi++;
      }
      else // 但如果当前最大的饼干都无法满足最大小朋友的胃口，则放弃分发给这个小朋友，找次贪心的小朋友
        gi++;

      // 直到分发完
    }

    return res;
  }
};

int main(void)
{
  vector<int> g1 = {1, 2, 3};
  vector<int> s1 = {1, 2};

  cout << Solution455().findContentChildren(g1, s1) << endl;

  return 0;
}
