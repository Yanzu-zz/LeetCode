#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution260
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) // 把次数都统计进来
      ++map[nums[i]];

    // 然后遍历哈希表，获取只出现一次的两个元素
    vector<int> res;
    for (const auto &[num, cnt] : map)
      if (cnt == 1)
        res.emplace_back(num);

    return res;
  }
};

int main()
{

  return 0;
}