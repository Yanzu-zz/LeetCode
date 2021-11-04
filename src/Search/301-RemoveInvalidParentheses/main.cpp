#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution301
{
private:
  // 查看传入的 str 的左右括号是否合法
  inline bool isValid(const string &str)
  {
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
      // 利用左右括号数目来判定，另外只要右括号出现在前面，就返回不合法
      if (str[i] == '(')
      {
        cnt++;
      }
      else if (str[i] == ')')
      {
        cnt--;
        if (cnt < 0)
          return false;
      }
    }

    return cnt == 0;
  }

  /**
   * 删除无效括号集合 helper 函数
   * str: 需要进行处理的括号字符串
   * start: 当前在字符串的哪个位置
   * lcount, rcount: 当前生成字符串中左右括号的数量
   * lremove, rremove: 原字符串中多余左右括号数量
   */
  void helper(string str, int start, int lcount, int rcount, int lremove, int rremove, vector<string> &res)
  {
    // 把多余数量的括号移除后，查看是否合法，合法加入 res
    if (lremove == 0 && rremove == 0)
    {
      if (isValid(str)) // 合法就加入
        res.push_back(str);
      return; // 否则啥也不干，只是返回去
    }

    for (int i = start; i < str.size(); i++)
    {
      // 不用哈希表去重的话，就这样剪枝，即
      // 我们在每次进行搜索时，如果遇到连续相同的括号我们只需要搜索一次即可，比如当前遇到的字符串为 \texttt{"(((())"}"(((())"，去掉前四个左括号中的任意一个，生成的字符串是一样的，均为 \texttt{"((())"}"((())"，因此我们在尝试搜索时，只需去掉一个左括号进行下一轮搜索，不需要将前四个左括号都尝试一遍。
      if (i != start && str[i] == str[i - 1])
        continue;

      // 如果剩余的字符无法满足去掉的数量要求，直接返回
      if (lremove + rremove > str.size() - i)
        return;

      // 尝试去掉一个左括号
      if (lremove > 0 && str[i] == '(')
        helper(str.substr(0, i) + str.substr(i + 1), i, lcount, rcount, lremove - 1, rremove, res);

      // 尝试去掉一个右括号
      if (rremove > 0 && str[i] == ')')
        helper(str.substr(0, i) + str.substr(i + 1), i, lcount, rcount, lremove, rremove - 1, res);

      if (str[i] == ')')
        lcount++;
      else if (str[i] == ')')
        rcount++;
      // 当前右括号的数量大于左括号的数量则为非法,直接返回
      if (rcount > lcount)
        break;
    }
  }

public:
  vector<string> removeInvalidParentheses(string s)
  {
    int lremove = 0, rremove = 0;
    // 统计多余的括号的数量
    for (char c : s)
    {
      if (c == '(')
      {
        lremove++;
      }
      else if (c == ')')
      {
        if (lremove == 0)
          rremove++;
        else
          lremove--;
      }
    }

    vector<string> res;
    helper(s, 0, 0, 0, lremove, rremove, res);
    return res;
  }
};

int main()
{
  string s1 = "()())()";
  vector<string> v1 = Solution301().removeInvalidParentheses(s1);
  for (auto i : v1)
    cout << i << "  ";

  return 0;
}