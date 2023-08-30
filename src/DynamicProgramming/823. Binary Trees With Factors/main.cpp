#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int numFactoredBinaryTrees(vector<int> &arr)
  {
    const int MOD = 1e9 + 7;
    // 这里如果用 unordered_set 就不好记忆化搜索
    unordered_map<int, int> idx;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
      idx[arr[i]] = i;

    // 定义 dfs函数
    // 这样写是因为可以少传 arr 和 unordered_set 参数
    vector<long long> memo(n, -1);
    function<long long(int)> dfs = [&](int i) -> long long
    {
      // 这里定义为 1 是因为自身也是一个二叉树
      long long &res = memo[i];
      if (res != -1)
        return res;

      res = 1;
      int val = arr[i];
      // 能分解的因子一定比 [i] 小
      for (int j = 0; j < i; j++)
      {
        int x = arr[j];
        int cur = val / x;
        if (val % x == 0 && idx.count(cur))
          res += dfs(j) * dfs(idx[cur]);
      }

      return res;
    };

    // 然后一个一个 count
    long long res = 0;
    for (int i = 0; i < n; i++)
      res += dfs(i);

    return res % MOD;
  }
};

int main(void)
{

  return 0;
}
