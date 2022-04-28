#include <iostream>
#include <vector>

using namespace std;

class Solution905
{
public:
  vector<int> sortArrayByParity(vector<int> &nums)
  {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left < right)
    {
      if (nums[left] & 1)
      {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;

        // 此时左指针不用动，因为要判断交换后的数字是不是奇数
        right--;
      }
      else
      {
        left++; // 如果是偶数则直接扩大范围即可
      }
    }

    return nums;
  }
};

int main(void)
{

  return 0;
}
