#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int countConsistentStrings(string allowed, vector<string> &words)
  {
    int res = 0, mask = 0;

    // 用位来代替数组作用
    for (char ch : allowed)
      mask |= 1 << (ch - 'a');

    for (string word : words)
    {
      int i = 0, len = word.size();
      // 查看当前字母是否允许出现
      for (; i < len && (mask >> (word[i] - 'a')) & 1; i++)
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
