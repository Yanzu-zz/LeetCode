#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 利用哈希表的唯一存储性即可完成
 */
class Solution217
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, bool> map;
    for (int i = 0; i < n; i++)
    {
      if (!map[nums[i]])
        map[nums[i]] = true;
      else
        return true;
    }

    // 找不到重复元素
    return false;
  }
};

int main(void)
{
  vector<int> arr1 = {1, 2, 3, 1};
  vector<int> arr2 = {1, 2, 3, 4, 5};

  cout << Solution217().containsDuplicate(arr1) << endl;
  cout << Solution217().containsDuplicate(arr2) << endl;

  return 0;
}
