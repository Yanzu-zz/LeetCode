#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution268
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int total = n * (n + 1) >> 1; // 高斯公式计算 0-n 的等差数列和
    //int arrSum = accumulate(nums.begin(), nums.end(), 0); // 传入的 nums 的全部元素和
    int arrSum = 0;
    for (const auto &num : nums)
      arrSum += num;

    // 那么所求 missing number 就是两数之差
    return total - arrSum;
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