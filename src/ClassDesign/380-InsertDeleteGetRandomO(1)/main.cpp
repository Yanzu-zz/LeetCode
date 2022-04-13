#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>

using namespace std;

class RandomizedSet
{
private:
  // 变长数组与哈希表
  vector<int> arr;
  unordered_map<int, int> mp;

public:
  RandomizedSet()
  {
    // 初始化随机种子
    srand((unsigned)time(NULL));
  }

  bool insert(int val)
  {
    // 不能插入已经存在的
    if (mp.count(val))
      return false;

    int idx = arr.size();
    arr.emplace_back(val);
    mp[val] = idx;
    return true;
  }

  bool remove(int val)
  {
    // 不能删除不存在的
    if (!mp.count(val))
      return false;

    // 我们将最后一个元素的值替换 val 元素索引处的值，接着删除这个最后一个元素
    // 这样利用哈希表不需要遍历就能删除
    int valIdx = mp[val];
    int last = arr.back();

    // 注意两个结构是对应的，一个变了另一个也要跟上
    arr[valIdx] = last;
    mp[last] = valIdx;
    arr.pop_back();
    mp.erase(val);

    return true;
  }

  int getRandom()
  {
    int idx = rand() % arr.size();
    return arr[idx];
  }
};

int main(void)
{

  return 0;
}
