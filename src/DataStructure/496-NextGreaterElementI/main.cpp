#include <iostream>
#include <vector>

using namespace std;

class Solution496
{
public:
  // 暴力
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> res(n1, -1);

    for (int i = 0; i < n1; i++)
    {
      int j = 0;
      while (nums1[i] != nums2[j]) // 在 nums2 中找对应的数字
        j++;

      while (j < n2 && nums1[i] >= nums2[j]) // 这里就是开始找右边第一个比当前元素大的值了
        j++;

      if (j < n2)
        res[i] = nums2[j];
    }

    return res;
  }
};

int main()
{

  return 0;
}