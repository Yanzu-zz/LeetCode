#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution15
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> res;

    // 先排序
    sort(nums.begin(), nums.end());

    // 然后就是开始遍历
    // 当前控制第一个数组位置，在它之前的数字都访问过了，不会再理会
    for (int first = 0; first < n; first++)
    {
      // 当前数字不能和上一个数组一致，不然就会重复
      if (first > 0 && nums[first] == nums[first - 1])
        continue;

      int third = n - 1;         // 提前定义一下第三个指针变量，我们这里不需要要开第三个循环
      int target = -nums[first]; // 第二个指针和第三个指针的任务就是相加起来等于 -nums[first]，这样它们三个变量相加就会等于0

      // 当前是控制第二个数字的变量，从 first 右边第一个数字开始遍历
      for (int second = first + 1; second < n - 1; second++)
      {
        // 和 first 一样，也不能重复，不然后面的 third 指针也是会和上一轮一样选择同样的数字
        if (second > first + 1 && nums[second] == nums[second - 1])
          continue;

        // 要是第二第三个变量相加的值比 target 还要大，那么就缩小第三个变量，使得它们的值慢慢接近 target（因为已经排好序了）
        // 注意，这里依然要保持第二个指针在第三个指针的左侧
        while (second < third && nums[second] + nums[third] > target)
          third--;

        // 边界条件判，这里是第二第三个指针相遇，则表明不可能再会有符合条件的数字位置了，就可以结束此轮循环，开始下个数字位置的寻找了
        if (second == third)
          break;

        // 这里就是此轮循环找到了题目要求的一组数组，我们把它们加进结果数组即可
        if (nums[second] + nums[third] == target)
          res.push_back({nums[first], nums[second], nums[third]});
      }
    }

    return res;
  }
};

int main()
{

  return 0;
}