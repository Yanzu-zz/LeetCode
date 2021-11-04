#include <iostream>
#include <vector>

using namespace std;

/**
 * 原始数组	1 2 3 4 5 6 7
 * 先翻转所有元素 7 6 5 4 3 2 1
 * 然后翻转 [0, k mod n - 1]区间的元素	5 6 7 4 3 2 1
 * 再翻转后面的 [k mod n, n - 1]区间的元素	5 6 7 1 2 3 4
 */
class Solution189
{
private:
  // 翻转 nums[left...rigt] 区间的元素
  void reverse(vector<int> &nums, int left, int right)
  {
    while (left < right)
      swap(nums[left++], nums[right--]);
  }

public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k %= n;

    // 先翻转全部数组
    reverse(nums, 0, n - 1);
    // 接着翻转前面的部分
    reverse(nums, 0, k - 1);
    // 最后翻转后面的
    reverse(nums, k, n - 1);
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
