#include <iostream>
#include <vector>

using namespace std;

class Solution78
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> tmp;
    vector<vector<int>> res;

    for (int mask = 0; mask < (1 << n); mask++)
    {
      tmp.clear();
      for (int i = 0; i < n; i++)
        if (mask & (1 << i))
          tmp.emplace_back(nums[i]);

      res.emplace_back(tmp);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
