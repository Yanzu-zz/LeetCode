#include <iostream>
#include <vector>

using namespace std;

struct GamerNode
{
  int val;
  bool flag = true;
};

class Solution1823
{
public:
  int findTheWinner(int n, int k)
  {
    // 初始化数组
    vector<GamerNode *> arr(n);
    for (int i = 0; i < n; i++)
      arr[i] = new GamerNode{i + 1};

    int curIdx = 0, totalRound = 0;
    while (totalRound < n)
    {
      int cnt = k;
      while (cnt > 0)
      {
        // 只考虑还没淘汰过的
        if (arr[curIdx]->flag)
          cnt--;

        // 找到当前的输家
        if (cnt == 0)
        {
          arr[curIdx]->flag = false;
          // 记录一轮次数
          totalRound++;
        }
        else
        {
          // 不管逃不淘汰，都到下个元素去
          curIdx = (curIdx + 1) % n;
        }
      }

      // 我们把最后一个人索引不点就得到了结果
      if (totalRound < n)
        // 到它的顺时针的下一位玩家位置上去
        curIdx = (curIdx + 1) % n;
    }

    return arr[curIdx]->val;
  }
};

int main(void)
{
  cout << Solution1823().findTheWinner(5, 2) << endl;

  return 0;
}
