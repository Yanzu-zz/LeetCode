#include <iostream>
#include <vector>

using namespace std;

/**
 * 想不到先暴力嘛哈哈哈
 */
class Solution153
{
public:
  int findMin(vector<int> &nums)
  {
    int n = nums.size(), i = 0;

    if (nums[0] > nums[n - 1])
      for (i = 1; nums[i] > nums[i - 1] && i < n; i++)
        ;

    return nums[i];
  }
};

int main(void)
{
  vector<int> arr1 = {3, 4, 5, 1, 2};
  vector<int> arr2 = {4, 5, 6, 7, 0, 1, 2};
  vector<int> arr3 = {11, 13, 15, 17};
  vector<int> arr4 = {1, 2, 3, 4, 5};

  cout << Solution153().findMin(arr1) << endl;
  cout << Solution153().findMin(arr2) << endl;
  cout << Solution153().findMin(arr3) << endl;
  cout << Solution153().findMin(arr4) << endl;

  return 0;
}
