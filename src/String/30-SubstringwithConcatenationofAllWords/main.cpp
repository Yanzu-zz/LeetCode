#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution30
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {
    int wordLen = words[0].size();
    unordered_map<string, int> mp;  // 记录 words 中各单词的出现个数
    unordered_map<string, int> tmp; // 每次窗口的临时哈希表

    for (string word : words)
      mp[word]++; // 记录

    int n = words.size();
    int len = s.size() - wordLen * n + 1;
    vector<int> res; // 记录题目要求的返回数组

    // 开始遍历滑动判断
    for (int i = 0; i < len; i++)
    {
      bool isValid = true;
      for (int j = 0; j < n; j++)
      {
        // 读取下个单词（题目给明每个单词是固定长度 wordLen）
        string curr = s.substr(i + j * wordLen, wordLen);
        // 单词不存在
        if (!mp[curr])
        {
          isValid = false;
          break;
        }

        tmp[curr]++;

        // 如果出现次数与 words 次数不匹配（即超过了）
        if (tmp[curr] > mp[curr])
        {
          isValid = false;
          break;
        }
      }

      // 如果检验都通过了就可以加入返回结果数组
      if (isValid)
        res.emplace_back(i);
      tmp.clear();
    }

    return res;
  }
};

int main()
{

  return 0;
}