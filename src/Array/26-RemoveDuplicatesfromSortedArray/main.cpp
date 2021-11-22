#include <iostream>
#include <vector>

using namespace std;

class Solution26
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    if (n < 2)
      return n;

    // 快慢指针
    // 看笔记理解
    int slow = 0;
    for (int fast = 1; fast < n; fast++)
      if (nums[fast] != nums[slow])
        nums[++slow] = nums[fast];

    return slow + 1; // 因为返回的是数组长度，故我们需要 + 1（因为索引从0开始）
  }
};

int main()
{

  return 0;
}