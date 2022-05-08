#include <iostream>
#include <vector>

using namespace std;

class Solution442
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res;

    // 将元素交换到对应的位置
    for (int i = 0; i < n; i++)
      while (nums[i] != nums[nums[i] - 1])
        swap(nums[i], nums[nums[i] - 1]);

    // 然后遍历检查那个元素不在对应位置就加入返回结果数组
    for (int i = 0; i < n; i++)
      if (nums[i] != i + 1)
        res.emplace_back(nums[i]);

    return res;
  }
};

int main(void)
{

  return 0;
}
