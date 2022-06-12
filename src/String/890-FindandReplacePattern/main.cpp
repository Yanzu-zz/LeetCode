#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution890
{
public:
  bool isMatch(string word, string pattern)
  {
    unordered_map<char, char> mp;

    int len = word.size();
    // 利用哈希表构造双射
    for (int i = 0; i < len; i++)
    {
      char x = word[i], y = pattern[i];
      if (!mp.count(x))
        mp[x] = y;
      else if (mp[x] != y) // 如果构造双射后某个位置发现不相等，则该字符串不是同构字符串
        return false;
    }

    return true;
  }

  vector<string> findAndReplacePattern(vector<string> &words, string pattern)
  {
    int n = words.size();
    vector<string> res;

    // 逐个构造双射，判断是否同构字符串
    for (int i = 0; i < n; i++)
      // 双向判断
      if (isMatch(words[i], pattern) && isMatch(pattern, words[i]))
        res.emplace_back(words[i]);

    return res;
  }
};

int main()
{

  return 0;
}