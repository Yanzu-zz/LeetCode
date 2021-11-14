#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class MapSum
{
private:
  unordered_map<string, int> cnt;

public:
  MapSum()
  {
  }

  void insert(string key, int val)
  {
    cnt[key] = val; // 利用哈希表的快速索引，简单粗暴
  }

  // 暴力扫描
  int sum(string prefix)
  {
    int res = 0;
    for (const auto &[key, val] : cnt)
      if (key.substr(0, prefix.size()) == prefix)
        res += val;

    return res;
  }
};

int main()
{

  return 0;
}