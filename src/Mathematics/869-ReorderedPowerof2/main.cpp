#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution869
{
private:
  const static int MOD = 1610612741;
  vector<string> powerOfTwo = {"1", "2", "4", "8", "16", "32", "64", "128", "256", "512", "1024", "2048", "4096", "8192", "16384", "32768", "65536", "131072", "262144", "524288", "1048576", "2097152", "4194304", "8388608", "16777216", "33554432", "67108864", "134217728", "268435456", "536870912"};
  vector<int> preHash;

  // 哈希函数
  int hash(string num)
  {
    int n = num.size();
    long res = 1;
    for (int i = 0; i < n; i++)
    {
      int ch = num[i];
      res = ((res % MOD) * (ch % MOD)) % MOD;
    }

    return (int)res;
  }

public:
  Solution869()
  {
    int n = powerOfTwo.size();
    preHash.resize(n);
    // 预处理哈希值
    for (int i = 0; i < n; i++)
      preHash[i] = hash(powerOfTwo[i]);
  }

  bool reorderedPowerOf2(int n)
  {
    int len = preHash.size();
    // 然后查找 n 的哈希值是否在 preHash 里面，有则可以重新排列数字称为 2的次幂
    int nHash = hash(to_string(n));
    for (int i = 0; i < len; i++)
      if (nHash == preHash[i])
        return true;

    return false;
  }
};

int main()
{
  Solution869 *st = new Solution869();
  cout << st->reorderedPowerOf2(46) << endl;
  cout << st->reorderedPowerOf2(89) << endl;
  cout << st->reorderedPowerOf2(10) << endl;

  return 0;
}