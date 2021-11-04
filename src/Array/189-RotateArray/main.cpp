#include <iostream>
#include <vector>

using namespace std;

/**
 * 第一时间想到开额外的空间解决（时间比空间值钱）
 */
class Solution189
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k %= n;
    vector<int> t;
    int i;
    for (i = n - k; i < n; i++)
      t.emplace_back(nums[i]);

    for (i = 0; i < n - k; i++)
      t.emplace_back(nums[i]);

    nums = t;
  }
};

int main(void)
{
  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};

  Solution189().rotate(arr1, 3);
  for (int i = 0; i < arr1.size(); i++)
    cout << arr1[i] << " ";
  cout << endl;

  return 0;
}
