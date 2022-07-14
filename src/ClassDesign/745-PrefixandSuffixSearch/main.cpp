#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 字典树
struct Trie
{
  unordered_map<string, Trie *> children;
  int weight;
};

class WordFilter
{
public:
  Trie *trie;

  WordFilter(vector<string> &words)
  {
    trie = new Trie();
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
      string word = words[i];
      int m = word.size();
      Trie *cur = trie;

      for (int j = 0; j < m; j++)
      {
        Trie *tmp = cur;
        // 因为需要查找的前后缀长度可能不一样，故需要额外处理
        // 注意，可能是在任何位置停下来，故这里每个位置都插入
        for (int k = j; k < m; k++)
        {
          string key({word[k], '#'});
          // 经典字典树插入操作了，不解释
          if (!tmp->children.count(key))
            tmp->children[key] = new Trie();

          tmp = tmp->children[key];
          tmp->weight = i;
        }

        // 回归指针，重复操作（从后到前）
        tmp = cur;
        for (int k = j; k < m; k++)
        {
          string key({'#', word[m - k - 1]});
          if (!tmp->children.count(key))
            tmp->children[key] = new Trie();

          tmp = tmp->children[key];
          tmp->weight = i;
        }

        // 合并前后缀插入
        string key({word[j], word[m - j - 1]});
        if (!cur->children.count(key))
          cur->children[key] = new Trie();

        cur = cur->children[key];
        cur->weight = i;
      }
    }
  }

  // 查找
  int f(string pref, string suff)
  {
    Trie *cur = trie;
    int len1 = pref.size(), len2 = suff.size();
    // 前后缀的长度可能不一样
    int m = max(len1, len2);
    for (int i = 0; i < m; i++)
    {
      char c1 = i < len1 ? pref[i] : '#';
      char c2 = i < len2 ? suff[len2 - i - 1] : '#';

      string key({c1, c2});
      if (!cur->children.count(key))
        return -1;

      cur = cur->children[key];
    }

    return cur->weight;
  }
};

int main(void)
{

  return 0;
}
