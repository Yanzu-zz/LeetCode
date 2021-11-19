#include <iostream>
#include <vector>

using namespace std;

class Solution16_2
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int res = 0, tmp = INT_MAX;
    for (int first = 0; first < n - 2; first++)
    {
      int second = first + 1, third = n - 1;
      while (second < third)
      {
        int sum = nums[first] + nums[second] + nums[third];
        int distance = abs(sum - target);
        // 更新距离
        if (distance < tmp)
        {
          tmp = distance;
          res = sum;
        }

        // 如果等于 target，那么最小的差值就是0，就返回当前值
        if (sum == target)
        {
          return sum;
        }
        else if (sum > target)
        {
          third--;
        }
        else
        {
          second++;
        }
      }
    }

    return res;
  }
};

int main()
{
  vector<int> arr1 = {0, 2, 1, -3};
  cout << Solution16_2().threeSumClosest(arr1, 1) << endl;

  vector<int> arr2 = {-1, 2, 1, -4};
  cout << Solution16_2().threeSumClosest(arr2, 1) << endl;

  return 0;
}