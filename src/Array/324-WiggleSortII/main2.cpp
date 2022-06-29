#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> bucket(5001, 0);
    for (int num : nums) // 桶排序
      bucket[num]++;

    // 然后两步两步的放置元素（先大的）
    // 题目保证一定会有解
    int j = 5000;
    for (int i = 1; i < n; i += 2)
    {
      while (!bucket[j])
        j--;

      nums[i] = j;
      bucket[j]--;
    }

    for (int i = 0; i < n; i += 2)
    {
      while (!bucket[j])
        j--;

      nums[i] = j;
      bucket[j]--;
    }
  }
};

int main(void)
{

  return 0;
}
