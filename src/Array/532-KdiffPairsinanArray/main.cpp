#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution532
{
public:
  int findPairs(vector<int> &nums, int k)
  {
    unordered_set<int> visited;
    unordered_set<int> res;

    for (int num : nums)
    {
      // 我们就保存较小的那个值，这要当大的值遍历到的时候就不会重复计算了
      if (visited.count(num - k))
        res.emplace(num - k);
      if (visited.count(num + k))
        res.emplace(num);

      // 将每个元素去重后添加，以便后面快速判断查找
      visited.emplace(num);
    }

    return res.size();
  }
};

int main()
{

  return 0;
}