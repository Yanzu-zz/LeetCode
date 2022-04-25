#include <iostream>
#include <vector>

using namespace std;

class Solution398_2
{
private:
  int n;
  vector<int> &nums;

public:
  Solution398_2(vector<int> &nums) : nums(nums)
  {
    n = nums.size();
  }

  int pick(int target)
  {
    // 蓄水池抽样
    int res, cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == target)
      {
        // 第 cnt 次遇到 target 元素
        ++cnt;
        // 这里不要 break
        if (rand() % cnt == 0)
          res = i;
      }
    }
    
    return res;
  }
};

int main(void)
{

  return 0;
}
