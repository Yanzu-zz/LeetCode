#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1200
{
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr)
  {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // 寻找最小差值
    int minAb = INT_MAX;
    for (int i = 1; i < n; i++)
    {
      int tmp = arr[i] - arr[i - 1];
      minAb = tmp < minAb ? tmp : minAb;
    }

    // 然后将相邻的两个元素做差，等于最小差值就将其加入到返回结果数组中
    //因为最小差值只能在相邻两个元素中出现
    vector<vector<int>> res;
    for (int i = 1; i < n; i++)
    {
      int tmp = arr[i] - arr[i - 1];
      // 找到就加入
      if (tmp == minAb)
        res.push_back({arr[i - 1], arr[i]});
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
