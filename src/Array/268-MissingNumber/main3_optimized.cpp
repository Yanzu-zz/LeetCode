#include <iostream>
#include <vector>

using namespace std;

class Solution268
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int res = 0;
    for (const auto &num : nums)
      res ^= num;

    // 我们并不需要操作原数组，我们可以先异或再 遍历异或 0-n 数字即可
    for (int i = 0; i <= n; i++)
      res ^= i;

    return res;
  }
};

int main()
{
  vector<int> arr1 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  cout << Solution268().missingNumber(arr1) << endl;

  vector<int> arr2 = {2, 0};
  cout << Solution268().missingNumber(arr2) << endl;

  vector<int> arr3 = {0};
  cout << Solution268().missingNumber(arr3) << endl;

  vector<int> arr4 = {0, 1};
  cout << Solution268().missingNumber(arr4) << endl;

  return 0;
}