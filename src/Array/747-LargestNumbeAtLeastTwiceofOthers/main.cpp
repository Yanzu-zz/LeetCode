#include <iostream>
#include <vector>

using namespace std;

class Solution747
{
public:
  int dominantIndex(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return 0;

    // 最大和第二大的元素
    int first = INT_MIN, second = INT_MIN;
    // 最大和第二大的元素的索引
    int firstIdx = -1;

    // 开始寻找
    for (int i = 0; i < n; i++)
    {
      int num = nums[i];
      if (num > first)
      {
        // 如果不加下面这一条语句，递增数组 second 会为空
        second = first;
        first = num;
        firstIdx = i;
      }
      // 如果不加下面的语句，递减数组的 second 为空
      else if (num > second)
        second = num;
    }

    // 不要使用 除法 来判断，因为 second 有可能为0，故我们用数学上等价的方式将 second*2 来和first比较即可
    // return first /second >= 2 ? firstIdx : -1;
    return first >= (second * 2) ? firstIdx : -1;
  }
};

int main(void)
{

  return 0;
}
