#include <iostream>
#include <vector>

using namespace std;

class Solution384
{
private:
  vector<int> nums;
  vector<int> original;

  void swap(vector<int> &nums, int i, int j)
  {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }

public:
  // 初始化
  Solution384(vector<int> &nums)
  {
    this->nums = nums;
    //this->original.resize(nums.size());
    //copy(nums.begin(), nums.end(), original.size());
    this->original = nums;
  }

  // 重置，直接拿存好的初始数组赋值就行
  vector<int> reset()
  {
    //copy(original.begin(), original.end(), nums.begin());
    this->nums = this->original;
    return nums;
  }

  // Fisher-Yates 洗牌算法
  vector<int> shuffle()
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      // 每次交换完（洗牌完），最后面的倒数第 i 个都是不用动了，只需要考虑前面即可
      int j = i + rand() % (n - i);
      swap(nums, i, j);
    }

    return nums;
  }
};

int main()
{

  return 0;
}