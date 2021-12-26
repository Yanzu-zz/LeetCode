#include <iostream>
#include <vector>

using namespace std;

class Solution1078
{
private:
  void pushWord(string text, int cur, vector<string> &res)
  {
    int n = text.size();
    string s = "";
    while (cur < n && text[cur] != ' ')
      s += text[cur++];

    if (cur <= n)
      res.emplace_back(s);
  }

public:
  vector<string> findOcurrences(string text, string first, string second)
  {
    string target = first + " " + second;
    vector<string> res;

    int cur = 0;
    int n = text.size(), m = target.size();
    while (cur <= n - m)
    {
      // 如果开头都不相等，直接 pass
      if (text[cur] != target[0])
      {
        cur++;
        continue;
      }

      // 暴力匹配
      int i = cur;
      for (; i < n && i < cur + m && text[i] == target[i - cur]; i++)
        ;

      // 如果没匹配上就 pass 到下一个单词的开头
      if (i < cur + m)
      {
        while (cur < n && text[cur] != ' ')
          cur++;

        continue;
      }
      // 匹配上了就把后面的词给加进 res
      // 注意，加入完后不能从加入这个词的后面一个词继续，而是应该从 这次开始匹配的单词的下一个单词继续
      // 如 we we we we will we will rock you，如 first=we, second=we 则会跳过一些词
      else
      {
        // 如果 m 个字符都对上了，则表明这个后面的单词就是我们要找的之一
        pushWord(text, i + 1, res);

        // 更新当前扫描到的索引到下个单词开头
        while (cur < n && text[cur] != ' ')
          cur++;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
