#include <iostream>
#include <vector>

using namespace std;

class Solution686
{
public:
  int repeatedStringMatch(string a, string b)
  {
    int m = b.size();
    string str = a;
    // 不够长度就补，直到长度大于 a 了
    while (str.size() <= m)
      str += a;
    str += a; // 这里还要补一次

    // 偷个懒用 find 函数，不自己写模式匹配函数了
    size_t found = str.find(b);
    // 没找到就表明 b 不可能是 a 的子串，a 怎么弄也无法包含 b
    if (found == string::npos)
      return -1;

    // 若找到了就可以用下面的方式计算 a 最少重复几次能包含 b
    return (m + found - 1) / a.size() + 1;
  }
};

int main(void)
{

  return 0;
}
