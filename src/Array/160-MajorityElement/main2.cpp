#include <iostream>
#include <vector>

using namespace std;

class Solution160_2
{
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    int candidate = nums[0], count = 0;

    // 众数的个数，至少比其他所有非众数加起来还要多1
    //（也就是众数这个选举人一定有足够多的人支持，他可能在遍历的中途下台，
    // 但是最终一定会再次上台，成功当选）
    for (int num : nums)
    {
      if (num == candidate)
      {
        count++;
      }
      else
      {
        count--;
        if (count < 0)
        {
          candidate = num;
          count = 0;
        }
      }
    }

    return candidate;
  }
};

int main(void)
{

  return 0;
}
