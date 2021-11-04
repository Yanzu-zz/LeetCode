#include <iostream>
#include <vector>

using namespace std;

void _print(vector<int> &arr)
{
  for (const auto &i : arr)
    cout << i << " ";
  cout << endl;
}

class Solution448_2
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {
    int n = nums.size();
    // 将每个元素转化为索引，并在原数组中奖这个索引位置的值 + n
    // 这样，没有出现在数组中的数字对应的索引位置的值就不会大于 n
    for (const auto &num : nums)
    {
      int idx = (num - 1) % n; // 因为有重复数字，所以有可能加这个数字索引的时候之前已经加过了，所以我们要求余
      nums[idx] += n;
    }

    // 每个位置的元素都加上 n 后，自身数值小于等于 n 的就是没有出现在原数组中的
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] <= n)
        res.push_back(i + 1);
    }

    return res;
  }
};

int main()
{
  vector<int> arr1 = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> res1 = Solution448_2().findDisappearedNumbers(arr1);
  _print(res1);

  return 0;
}