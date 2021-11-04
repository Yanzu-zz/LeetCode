#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * 回溯解法，难点在于如何去重
 */
class Solution216
{
public:
  vector<int> temp;
  vector<vector<int>> ans;

  void dfs(int cur, int n, int k, int sum)
  {
    if (temp.size() + (n - cur + 1) < k || temp.size() > k)
    {
      return;
    }
    if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum)
    {
      ans.push_back(temp);
      return;
    }

    temp.push_back(cur);
    dfs(cur + 1, n, k, sum);
    temp.pop_back();
    dfs(cur + 1, n, k, sum);
  }

  vector<vector<int>> combinationSum3(int k, int n)
  {
    dfs(1, 9, k, n);
    return ans;
  }
};

int main(void)
{
  int k1 = 3, n1 = 7;
  vector<vector<int>> arr1 = Solution216().combinationSum3(k1, n1);
  for (int i = 0; i < arr1.size(); i++)
    for (int j = 0; j < k1; j++)
      cout << arr1[i][j] << " ";
  cout << endl;

  int k2 = 3, n2 = 9;
  vector<vector<int>> arr2 = Solution216().combinationSum3(k2, n2);
  for (int i = 0; i < arr2.size(); i++)
    for (int j = 0; j < k2; j++)
      cout << arr2[i][j] << " ";
  cout << endl;

  return 0;
}
