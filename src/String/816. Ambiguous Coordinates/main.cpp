#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> ambiguousCoordinates(string s)
  {
    vector<string> res;

    s = s.substr(1, s.size() - 2); // 去掉开头和结尾的括号
    int n = s.size();
    // 开始暴力生成每个排列组合
    for (int l = 1; l < n; l++)
    {
      // 左坐标 x
      vector<string> lt = getPos(s.substr(0, l));
      if (lt.empty())
        continue;

      // 右坐标 y
      vector<string> rt = getPos(s.substr(l));
      if (rt.empty())
        continue;

      // 开始拼接
      for (auto x : lt)
        for (auto y : rt)
          res.emplace_back("(" + x + ", " + y + ")");
    }

    return res;
  }

  vector<string> getPos(string s)
  {
    vector<string> pos;
    // 只要开头不是 0，就可以不处理，直接加入结果数组
    if (s[0] != '0' || s == "0")
      pos.emplace_back(s);

    int n = s.size();
    for (int i = 1; i < n; i++)
    {
      // 0 不能作为开头
      if (i != 1 && s[0] == '0' || s.back() == '0')
        continue;

      // 把每种排列都加进去
      pos.emplace_back(s.substr(0, i) + "." + s.substr(i));
    }

    return pos;
  }
};

int main(void)
{

  return 0;
}
