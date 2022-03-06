#include <iostream>
#include <vector>

using namespace std;

class Solution2100
{
public:
  vector<int> goodDaysToRobBank(vector<int> &security, int time)
  {
    int n = security.size();
    vector<int> res;

    if (n < time)
      return res;

    // 前后 dp 数组，记录的是连续 递增/递减 的天数
    vector<int> pre(n, 1);
    vector<int> post(n, 1);

    // 初始化 pre/post 数组
    for (int i = 1; i < n - time; i++)
    {
      if (security[i] <= security[i - 1])
        pre[i] = pre[i - 1] + 1;

      // 利用索引偏移一次初始化两个数组
      if (security[n - i - 1] <= security[n - i])
        post[n - i - 1] = post[n - i] + 1;
    }

    // 正式遍历
    for (int i = time; i < n - time; i++)
    {
      if (pre[i] > time && post[i] > time)
        res.emplace_back(i);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
