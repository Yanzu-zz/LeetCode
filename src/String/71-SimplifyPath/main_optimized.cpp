#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution71
{
public:
  string simplifyPath(string path)
  {
    int n = path.size();
    string res = "";
    stack<string> stk;
    vector<string> names;

    int i = 0;
    // 开头的连续 "/" 也要跳过
    while (i < n && path[i + 1] == '/')
      i++;
    while (i < n)
    {
      // 遇到了 slash 就需要将后面的字符串入栈
      if (path[i] == '/')
      {
        if (i == n - 1)
          break;

        int j = i + 1;
        // 寻找后面字符串的边界
        while (j < n && path[j] != '/')
          j++;

        stk.push(path.substr(i + 1, j - i - 1));

        // 快速移动到下个 "/" 位置
        i = j;
        // 还需要判断连续 "//" 情况
        while (i < n && path[i + 1] == '/')
          i++;
      }
    }

    // 出栈并处理目录项元素
    while (!stk.empty())
    {
      string tmp = stk.top();
      stk.pop();

      if (tmp == ".")
      {
        continue;
      }
      else if (tmp == "..")
      {
        int dotCnt = 1;
        // 如果当前出栈字符串为 ".."，则需要继续循环向前判断是否是连续的 ".."，并忽略后面相应的字符串
        while (!stk.empty())
        {
          string dotTmp = stk.top();
          // 只要下个出栈元素不为 ".." 了，就可以终止了
          if (dotTmp != "..")
            break;

          // 否则记录其数量并继续出栈判断
          dotCnt++;
          stk.pop();
        }

        // 忽略对应的个数
        while (dotCnt > 0 && !stk.empty())
        {
          string top = stk.top();
          if (top == ".")
            ; // do not thing
          else if (top == "..")
            dotCnt++;
          else
            dotCnt--;
          stk.pop();
        }

        // if (dotCnt > 0 && stk.empty())
        //  return "/";
      }
      // 正常目录项和文件项情况
      else
      {
        names.emplace_back(tmp);
      }
    }

    for (int i = names.size() - 1; i >= 0; i--)
      res.append(names[i] + "/");

    return "/" + res.substr(0, res.size() - 1);
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
