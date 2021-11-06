#include <iostream>
#include <vector>

using namespace std;

class Solution268
{
public:
  int missingNumber(vector<int> &nums)
  {
    nums.resize(nums.size() + 1);
    int n = nums.size();
    // 因为修改的是原数组，故遍历到后面的数字时可能已经被改动了，所以我们要 mod 一下之前加的数字来还原之前的
    for (int i = 0; i < n; i++)
      nums[nums[i] % n] += n;

    for (int i = 0; i < n; i++)
      if (nums[i] < n)
        return i;

    return 0;
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