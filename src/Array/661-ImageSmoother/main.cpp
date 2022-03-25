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

    // 开始暴力每个元素
    for (int i = 0; i < m; i++)
    {
      int sum = 0;
      // 确定每个元素的平滑区间
      int top = max(i - 1, 0), bottom = min(i + 1, m - 1); // 这一行的元素的平滑区间高度是固定的
      int left = 0, right = 0;

      for (int j = 0; j < n; j++)
      {
        sum = 0;
        left = max(j - 1, 0), right = min(j + 1, n - 1); // 左右区间随着这一列的元素位置变换而变换

        // 开始计算这一区域的和
        for (int x = top; x <= bottom; x++)
          for (int y = left; y <= right; y++)
            sum += img[x][y];

        res[i][j] = sum / ((right - left + 1) * (bottom - top + 1));
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
