#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findClosest(vector<string> &words, string word1, string word2)
  {
    int n = words.size();
    int w1 = -1, w2 = -1; // 两个单词的索引
    int res = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      // 记录索引
      if (words[i] == word1)
        w1 = i;
      else if (words[i] == word2)
        w2 = i;

      // 对比
      if (w1 >= 0 && w2 >= 0)
        res = min(res, abs(w1 - w2));
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
