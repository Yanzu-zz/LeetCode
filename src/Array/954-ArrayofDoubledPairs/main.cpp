#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution954
{
public:
  bool canReorderDoubled(vector<int> &arr)
  {
    unordered_map<int, int> mp;
    vector<int> vals;

    for (int num : arr)
      mp[num]++;

    // 如果没有偶数个0，则不可能配对成功
    if (mp[0] % 2)
      return false;

    // 接下来就是去重按放入 vals 数组
    vals.reserve(mp.size());
    for (auto &[x, _] : mp)
      vals.push_back(x);
    sort(vals.begin(), vals.end(), [](int a, int b)
         { return abs(a) < abs(b); });

    // 最后就是看 x 和 2*x 数量是否对的上
    for (int x : vals)
    {
      if (mp[2 * x] < mp[x])
        return false;

      mp[2 * x] -= mp[x];
    }

    return true;
  }
};

int main(void)
{
  vector<int> arr1 = {1, 2, 4, 16, 8, 4};
  cout << Solution954().canReorderDoubled(arr1) << endl;

  return 0;
}
