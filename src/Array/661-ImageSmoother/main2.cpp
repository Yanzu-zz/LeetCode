#include <iostream>
#include <vector>

using namespace std;

class Solution661
{
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img)
  {
    int m = img.size(), n = img[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));

    // 计算前缀和
    // pre[i][j] 对应 img[i-1][j-1] 的二维前缀和
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        // 即上面一个元素的二维前缀和 + 左边一个元素的前缀和 - 重叠的部分 + img 当前格子的值，就是当前位置的前缀和了
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + img[i - 1][j - 1];

    // 开始计算
    for (int i = 0; i < m; i++)
    {
      int sum;
      // 获取上下左右边界（和遍历方法一样）
      int top = max(i - 1, 0), bottom = min(i + 1, m - 1);
      int left = 0, right = 0;

      for (int j = 0; j < n; j++)
      {
        sum = 0;
        left = max(j - 1, 0), right = min(j + 1, n - 1);

        // 然后就是计算，这里不用两层循环，用前缀和
        int cnt = (right - left + 1) * (bottom - top + 1);
        // 自己对照笔记的图想为什么这样加减（其实和上面计算前缀和思想一致，减去左和上，补上重叠部分）
        sum = pre[bottom + 1][right + 1] - pre[top][right + 1] - pre[bottom + 1][left] + pre[top][left];

        res[i][j] = sum / cnt;
      }
    }

    return res;
  }
};

int main(void)
{
  vector<vector<int>> arr1 = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
  Solution661().imageSmoother(arr1);

  return 0;
}
