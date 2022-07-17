#include <iostream>
#include <vector>

using namespace std;

class Solution562_2
{
public:
  int arrayNesting(vector<int> &nums)
  {
    int n = nums.size(), res = 0;

    // 这里我们用 nums 原数组做 vis 标记的效果，即遍历过的元素赋值 n，这个数字原数组不会达到
    for (int i = 0; i < n; i++)
    {
      int cnt = 0, curIdx = i;
      while (nums[curIdx] < n)
      {
        int tmp = nums[curIdx];
        nums[curIdx] = n;
        curIdx = tmp;
        cnt++;
      }

      res = cnt > res ? cnt : res;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
