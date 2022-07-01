#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution241
{
public:
  unordered_map<string, vector<int>> mp; // 记录字串结果

  int parseInt(string str)
  {
    int n = str.size();
    for (int i = 0; i < n; i++)
      if (str[i] < '0' || str[i] > '9')
        return -1;

    return stoi(str);
  }

  vector<int> dfs(string str)
  {
    int num = parseInt(str);

    // 边界条件，到了单个数字
    if (num >= 0)
    {
      return {num};
    }

    if (mp.count(str))
      return mp[str];

    int n = str.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      char ch = str[i];
      // 当遇到了符号的时候，就开始递归（分治）计算它们左右两边的字串的结果
      if (ch == '+' || ch == '-' || ch == '*')
      {
        vector<int> left = dfs(str.substr(0, i));
        vector<int> right = dfs(str.substr(i + 1));

        // 然后开始逐个计算
        // 也就是不同符号的优先级不同，会有不同的结果，这些结果都存在 left 和 right 数组里面了
        int val = 0;
        for (int l : left)
        {
          for (int r : right)
          {
            switch (ch)
            {
            case '+':
              val = l + r;
              break;
            case '-':
              val = l - r;
              break;
            case '*':
              val = l * r;
              break;
            default:
              break;
            }

            // 然后在这一层上，也逐渐建立子结果
            res.emplace_back(val);
          }
        }
      }
    }

    mp[str] = res;
    return res;
  }

  vector<int> diffWaysToCompute(string expression)
  {
    return dfs(expression);
  }
};

int main(void)
{

  return 0;
}
