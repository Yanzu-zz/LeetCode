#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int n = nums.size(), cnt = 0; // cnt 为递减次数，最多为 1

    // 遍历数组查看是否符合要求
    for (int i = 1; i < n && cnt <= 1; i++)
      cnt += (nums[i] < nums[i - 1]);

    return (cnt == 0) || (cnt == 1 && nums[0] >= nums[n - 1]);
  }
};

int main(void)
{

  return 0;
}
