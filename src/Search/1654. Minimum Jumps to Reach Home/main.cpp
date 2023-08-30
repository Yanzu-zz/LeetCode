#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int minimumJumps(vector<int> &forbidden, int a, int b, int x)
  {
    unordered_set<int> s(forbidden.begin(), forbidden.end());
    queue<pair<int, int>> q;
    q.emplace(0, 1);

    // 右边界
    const int LIMIT = 6000;
    // 记录是否能往回跳，true可以往回跳
    bool vis[LIMIT][2];
    memset(vis, false, sizeof(vis));
    vis[0][1] = true;

    for (int ans = 0; q.size() != 0; ans++)
    {
      for (int t = q.size(); t > 0; t--)
      {
        // 拿到当前跳到的位置
        auto [i, k] = q.front();
        q.pop();

        // 达到题目的位置
        if (i == x)
          return ans;

        // 没达到则继续枚举跳呗
        // nxts 存放当前点位往前和往后跳能到达的点位
        // 这里先只存放往前跳的点位的信息，因为往后跳可能被限制了
        vector<pair<int, int>> nxts = {{i + a, 1}};
        // 判断下如果能往后跳就往nxts里面加
        // 当然，等下到了这个往后跳的点位，就不能继续往后跳了，只能连续往后跳一次
        if (k & 1)
          nxts.emplace_back(i - b, 0);

        // 接着就是枚举 nxts 往前往后跳了（即使可能只能跳一次）
        // 只要进了 nxts 数组，且之前没被枚举过，都能进入 queue 队列
        for (auto [j, l] : nxts)
        {
          // 若下个点为在边界内，且不在限制点数组内，且之前没有被枚举过，则加入数组
          // 如果被枚举过，则肯定不用再算一次
          if (j >= 0 && j < LIMIT && !s.count(j) && !vis[j][l]){
            vis[j][l] = true;
            q.emplace(j, l);
          }
        }
      }
    }

    return -1;
  }
};

int main(void)
{

  return 0;
}
