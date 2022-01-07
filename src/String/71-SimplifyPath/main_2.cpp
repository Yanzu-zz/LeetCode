#include <iostream>
#include <vector>

using namespace std;

class Solution71
{
public:
  string simplifyPath(string path)
  {
    int n = path.size();

    auto split = [](const string &s, char delim) -> vector<string>
    {
      vector<string> res;
      string cur;

      for (char ch : s)
      {
        // 遇到分割符就将这段距离内 append 的字符串加入返回结果数组
        if (ch == delim)
        {
          res.emplace_back(move(cur));
          cur.clear();
        }
        else
        {
          cur += ch;
        }
      }

      res.emplace_back(move(cur));
      return res;
    };

    vector<string> names = split(path, '/');

    // 开始处理路径字符串
    vector<string> stk;
    for (string &name : names)
    {
      // 若遇到 .. 就将对应的目录抛弃
      // 而 names 又是从左到右的顺序，不是正常栈的顺序，故这样是可以的
      if (name == "..")
      {
        if (!stk.empty())
          stk.pop_back();
      }
      // stk 只加入非 . 和 .. 的字符串
      else if (!name.empty() && name != ".")
      {
        stk.emplace_back(move(name));
      }
    }

    // 接下来就是拼接结果字符串
    string res;
    if (stk.empty())
      res = "/";
    else
      for (string &name : stk)
        res += "/" + move(name);

    return res;
  }
};

int main(void)
{
  string s0 = "/home/";
  cout << Solution71().simplifyPath(s0) << endl;

  string s1 = "/root/code";
  cout << Solution71().simplifyPath(s1) << endl;

  string s2 = "/root/./code";
  cout << Solution71().simplifyPath(s2) << endl;

  string s3 = "/root/../code";
  cout << Solution71().simplifyPath(s3) << endl;

  string s4 = "/root/../../code";
  cout << Solution71().simplifyPath(s4) << endl;

  string s5 = "/dev/sbd/../code";
  cout << Solution71().simplifyPath(s5) << endl;

  string s6 = "/proc/";
  cout << Solution71().simplifyPath(s6) << endl;

  string s7 = "/a/./b/../../c/";
  cout << Solution71().simplifyPath(s7) << endl;

  return 0;
}
