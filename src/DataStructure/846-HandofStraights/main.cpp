#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution846
{
public:
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    int n = hand.size();

    // 特判
    if (n % groupSize != 0 || n == 0)
      return false;
    if (groupSize == 1)
      return true;
    if (n == 2)
      return hand[1] == hand[0] + 1 || hand[0] == hand[1] + 1;

    unordered_map<int, int> mp;
    // 排序且将元素加入哈希表
    sort(hand.begin(), hand.end());
    for (int x : hand)
      mp[x]++;

    // 接着就是判断是否能够重新排列了
    // 具体是到 n-groupSize，因为到这一步后面的数就没有意义了
    for (int i = 0; i <= n - groupSize; i++)
    {
      int x = hand[i];
      // 如果哈希表中记录的当前元素个数为0，则表明它与前面的元素重新排列过了
      // 注意，这里顺便将自身的个数 - 1
      if (mp[x]-- <= 0)
        continue;

      // 查看当前元素是否能连续 groupSize 个
      for (int j = 1; j < groupSize; j++)
        if (mp[x + j]-- <= 0) // 如果发现途中有连续元素不存在，那就表明数组不能被重新排列
          return false;
    }

    // 上述条件都符合就表明这个数组可以被重新排列
    return true;
  }
};

int main(void)
{

  return 0;
}
