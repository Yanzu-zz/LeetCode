#include <iostream>
#include <vector>

using namespace std;

/**
 * 如果偷窃了第一间房屋，则不能偷窃最后一间房屋，因此偷窃房屋的范围是第一间房屋到最后第二间房屋；
 * 如果偷窃了最后一间房屋，则不能偷窃第一间房屋，因此偷窃房屋的范围是第二间房屋到最后一间房屋。
 * 和 198 题一模一样，只不过这里要rob两次试试看谁收益更高
 */
class Solution213
{
private:
  int tryRob(vector<int> &nums, int left, int right)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int a = nums[left], b, c;
    if (left + 1 < n)
      b = max(a, nums[left + 1]);
    else
      b = a;
    c = b;

    for (int i = left + 2; i < right; i++)
    {
      c = max(a + nums[i], b); // 选择抢或者不抢
      a = b;
      b = c;
    }

    return c;
  }

public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    return max(tryRob(nums, 0, n - 1), tryRob(nums, 1, n));
  }
};

int main(void)
{
  vector<int> arr1 = {2, 3, 2};
  vector<int> arr2 = {1, 2, 3, 1};
  vector<int> arr3 = {1, 2};

  cout << Solution213().rob(arr1) << endl;
  cout << Solution213().rob(arr2) << endl;
  cout << Solution213().rob(arr3) << endl;

  return 0;
}
