#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 暴力解法（超时）
 */
class Solution219
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (k >= n)
      k = n - 1;

    int i, j;
    for (i = k; i < n; i++)
    {
      for (j = i - k; j < n && j < i + k && j != i; j++)
      {
        if (nums[i] == nums[j])
          return true;
      }
    }

    return false;
  }
};

int main(void)
{
  vector<int> arr1 = {1, 2, 3, 1};
  vector<int> arr2 = {1, 0, 1, 1, 1};
  vector<int> arr3 = {1, 2, 3, 1, 2, 3};
  vector<int> arr4 = {99, 99};
  vector<int> arr5 = {8};

  cout << Solution219().containsNearbyDuplicate(arr1, 3) << endl;
  cout << Solution219().containsNearbyDuplicate(arr2, 1) << endl;
  cout << Solution219().containsNearbyDuplicate(arr3, 2) << endl;
  cout << Solution219().containsNearbyDuplicate(arr4, 2) << endl;
  cout << Solution219().containsNearbyDuplicate(arr5, 2) << endl;

  return 0;
}
