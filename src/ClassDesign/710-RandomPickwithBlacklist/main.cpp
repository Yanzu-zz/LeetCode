#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int bound;
  unordered_map<int, int> map; // 映射数组

  Solution(int n, vector<int> &blacklist)
  {
    int m = blacklist.size();
    bound = n - m;
    unordered_set<int> tmp;
    // 准备映射初始条件
    for (int b : blacklist)
    {
      if (b >= bound)
        tmp.emplace(b);
    }

    // 开始映射
    int currMapPointer = bound;
    for (int b : blacklist)
    {
      // 这里不用处理 大于等于 bound 的元素
      if (b < bound)
      {
        // 如果当前映射指针遇到了 黑名单 里面的数值，则往后走
        while (tmp.count(currMapPointer))
          currMapPointer++;

        map[b] = currMapPointer++; // 映射！
      }
    }
  }

  int pick()
  {
    int r = rand() % bound; // 这样大于 bound 的都不会取到
    return map.count(r) ? map[r] : r;
  }
};

int main(void)
{

  return 0;
}
