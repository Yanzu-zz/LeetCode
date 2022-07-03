#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution556
{
public:
  int nextGreaterElement(int n)
  {
    // 解题思路就是将数字转换成字符串后找到下一个全排列
    auto nums = to_string(n);
    int i = (int)nums.length() - 2;

    // 开始找下一个全排列
    while (i >= 0 && nums[i] >= nums[i + 1])
      i--;
    if (i < 0)
      return -1;

    int j = nums.size() - 1;
    while (j >= 0 && nums[i] >= nums[j])
      j--;

    swap(nums[i], nums[j]);
    reverse(nums.begin() + i + 1, nums.end());

    long ans = stol(nums);
    return ans > INT_MAX ? -1 : ans;
  }
};

int main(void)
{

  return 0;
}
