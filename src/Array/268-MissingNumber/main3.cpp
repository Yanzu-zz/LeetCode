#include <iostream>
#include <vector>

using namespace std;

class Solution268
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i <= n; i++)
      nums.push_back(i);
    n = nums.size();

    // 除了所求的 missing number 只会出现一次，其余元素均会出现两次，这样它们都抵消掉了，剩下的只能是 missing number 了
    int res = 0;
    for (const auto &num : nums)
      res ^= num;

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