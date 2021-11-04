#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void _print(vector<int> &arr)
{
  for (const auto &i : arr)
    cout << i << " ";
  cout << endl;
}

class Solution448
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, int> memo;

    // 将数组全部元素都添加进哈希表中
    for (int i = 0; i < n; i++)
      memo[nums[i]]++;

    // 然后从 1 遍历到 maxVal，当某个索引值不存在哈希表中时，添加进待返回数组
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
      if (memo[i] == 0)
        res.push_back(i);
    }

    return res;
  }
};

int main()
{
  vector<int> arr1 = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> res1 = Solution446().findDisappearedNumbers(arr1);
  _print(res1);

  return 0;
}