#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 哈希表
 */
class Solution219
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n == 1 || k == 0)
      return false;

    unordered_set<int> numsSet;
    numsSet.insert(nums[0]);

    int t;
    for (int i = 1; i < n; i++)
    {
      t = nums[i];
      if (numsSet.find(t) != numsSet.end()) // 在滚动窗口中找到了
        return true;

      numsSet.insert(t);
      if (numsSet.size() > k)
        numsSet.erase(nums[i - k]); // 抹掉窗口长度前的元素
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
