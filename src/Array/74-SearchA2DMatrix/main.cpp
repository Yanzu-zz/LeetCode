#include <iostream>
#include <vector>

using namespace std;

/**
 * 解题思路：因为题目说了数组是按从大到小排序的，因此我们只需判断每一行的最后一个元素是否大于等于 target
 * 若大于等于 target，则在该行进行二分搜索，找到返回 true，否则 false
 */
class Solution74
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int m = matrix.size(), n = matrix[0].size();

    int i, posLine = 0;
    // 找到 target 所可能存在的列
    for (i = 0; i < m; i++)
      if (matrix[i][n - 1] >= target)
      {
        if (matrix[i][n - 1] == target)
          return true;

        posLine = i;
        break;
      }

    // 开始二分搜索，找到返回 true，否则 false
    // i 表示左指针，j 表示右指针
    i = 0;
    int j = n - 1;
    int mid;
    while (i <= j)
    {
      mid = i + (j - i) / 2;              // 防溢出算中间值法
      if (matrix[posLine][mid] == target) // 找到返回 true 即可
        return true;
      else if (matrix[posLine][mid] > target)
        j = mid - 1;
      else
        i = mid + 1;
    }

    return false;
  }
};

int main(void)
{
  vector<vector<int>> arr1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  vector<vector<int>> arr2 = {{1, 3, 5}};

  cout << Solution74().searchMatrix(arr1, 3) << endl;
  cout << Solution74().searchMatrix(arr2, 1) << endl;

  return 0;
}
