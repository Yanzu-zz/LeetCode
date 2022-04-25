#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution398
{
private:
  unordered_map<int, vector<int>> mp; // 存储对应数字出现索引位置的哈希表

public:
  Solution398(vector<int> &nums)
  {
    int n = nums.size();
    // 保存信息
    for (int i = 0; i < n; i++)
      mp[nums[i]].emplace_back(i);
  }

  int pick(int target)
  {
    auto &pickNumArr = mp[target];
    // 随机化选择
    return pickNumArr[rand() % pickNumArr.size()];
  }
};

int main(void)
{

  return 0;
}
