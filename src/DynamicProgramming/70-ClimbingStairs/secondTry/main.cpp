#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution70
{
private:
  int recurtion(unordered_map<int, int> &mp, int n)
  {
    if (n <= 0)
      return 0;
    else if (n <= 2)
      return n;

    // 记忆化搜索
    if (mp[n] != 0)
      return mp[n];

    int result = recurtion(mp, n - 1) + recurtion(mp, n - 2);
    mp[n] = result;
    return result;
  }

public:
  int climbStairs(int n)
  {
    unordered_map<int, int> mp;
    return recurtion(mp, n);
  }
};

int main(void)
{

  return 0;
}
