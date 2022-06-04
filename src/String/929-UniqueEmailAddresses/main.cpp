#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution929
{
public:
  int numUniqueEmails(vector<string> &emails)
  {
    int res = 0;
    unordered_map<string, int> mp; // 出现过的 email 哈希表

    for (string email : emails)
    {
      // 模拟处理 email 字符串
      int len = email.size();
      string tmp = "";

      // 开始模拟处理 singular email
      int i = 0;
      for (; email[i] != '@';)
      {
        char ch = email[i];
        // 遇到 + 后面的字符串 至 @ 之间的都忽略
        if (ch == '+')
        {
          while (email[i] != '@')
            i++;
          break;
        }

        // local name 忽略 .
        if (ch != '.')
          tmp += ch;
        i++;
      }

      // 然后就是原封不动的赋值 domain section
      for (; i < len; i++)
        tmp += email[i];

      // 然后对比当前新的 email 是否唯一
      if (mp[tmp] == 0)
        res++;

      // 存入哈希表
      mp[tmp]++;
    }

    return res;
  }
};

int main()
{

  return 0;
}