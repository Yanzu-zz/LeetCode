#include <iostream>
#include <vector>

using namespace std;

/**
 * 解题思路：既然两个数组是有序的，我们参照归并排序的合并思想进行合并即可
 * 最后覆盖 nums1 数组即可
 */
class Solution88
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int len = m + n;
    vector<int> mergeArr;

    int lCur = 0, rCur = 0;
    while (lCur < m || rCur < n)
    {
      // 当某个数组全部覆盖完后另一个数组的元素直接加进去即可，无需再判断了
      if (lCur >= m)
        mergeArr.push_back(nums2[rCur++]);
      else if (rCur >= n)
        mergeArr.push_back(nums1[lCur++]);
      else if (nums1[lCur] < nums2[rCur])
        mergeArr.push_back(nums1[lCur++]);
      else
        mergeArr.push_back(nums2[rCur++]);
    }

    for (int i = 0; i < len; i++)
      nums1[i] = mergeArr[i];
  }
};

int main(void)
{
  vector<int> arr1 = {1, 2, 3, 0, 0, 0}, arr2 = {2, 5, 6};
  int m1 = 3, n1 = 3;

  Solution88().merge(arr1, m1, arr2, n1);
  for (int i = 0; i < arr1.size(); i++)
    cout << arr1[i] << " ";
  cout << endl;

  return 0;
}
