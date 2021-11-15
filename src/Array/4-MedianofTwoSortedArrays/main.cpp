#include <iostream>
#include <vector>

using namespace std;

class Solution4
{
private:
  // 归并排序的合并逻辑
  vector<int> _merge(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0, j = 0;
    vector<int> res;

    while (i < n1 || j < n2)
    {
      // 单个数组越界情况
      if (i >= n1)
      {
        res.push_back(nums2[j++]);
        continue;
      }
      else if (j >= n2)
      {
        res.push_back(nums1[i++]);
        continue;
      }

      if (nums1[i] <= nums2[j])
        res.push_back(nums1[i++]);
      else
        res.push_back(nums2[j++]);
    }

    return res;
  }

public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int len = nums1.size() + nums2.size();

    vector<int> merged = _merge(nums1, nums2);
    if (len % 2 == 0)
      return (merged[len / 2] + merged[len / 2 - 1]) / 2.0;
    else
      return merged[len / 2];
  }
};

int main()
{

  return 0;
}