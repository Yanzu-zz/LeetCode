#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int countConsistentStrings(string allowed, vector<string> &words)
  {
    int res = 0;
    vector<bool> set(26, false);

    // 保存允许出现的字母字符
    for (char ch : allowed)
      set[ch - 'a'] = true;

    // 开始验证 valid 的数量
    for (string word : words)
    {
      int i = 0, len = word.size();
      for (; i < len && set[word[i] - 'a']; i++)
        ;

      if (i == len)
        res++;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
