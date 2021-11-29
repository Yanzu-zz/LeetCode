#include <iostream>
#include <vector>

using namespace std;

class Solution786
{
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
  {
    int n = arr.size();
    // 存储每个素数分数结果的数组
    vector<pair<int, int>> frac;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        frac.emplace_back(arr[i], arr[j]); // 这里我们用数学上等价的形式存储，省去了浮点数运算的消耗

    // 下面就是排序，将各个素数分数结果自定义比较
    sort(frac.begin(), frac.end(), [&](const auto &x, const auto &y)
         { return x.first * y.second < x.second * y.first; });

    //然后返回题目要求的第k小即可
    return {frac[k - 1].first, frac[k - 1].second};
  }
};

int main()
{

  return 0;
}