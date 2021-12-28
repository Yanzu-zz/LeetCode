#include <iostream>
#include <vector>

using namespace std;

class Trie
{
public:
  vector<Trie *> children;
  bool isWord;

  Trie() : children(26), isWord(false) {}

  void insert(string word)
  {
    Trie *node = this;
    for (char ch : word)
    {
      ch -= 'a';
      if (node->children[ch] == nullptr)
        node->children[ch] = new Trie();

      node = node->children[ch];
    }

    // 最后标记一下这个节点是一个单词
    node->isWord = true;
  }

  // 搜索单词
  bool isConcatenedWord(string word)
  {
    int wordCnt = 0;
    Trie *node = this;
    for (char ch : word)
    {
      ch -= 'a';
      if (node->children[ch] == nullptr)
        return false;

      if (node->isWord)
        wordCnt++;
      node = node->children[ch];
    }

    return node != nullptr && node->isWord && wordCnt >= 2;
  }
};

class Solution472
{
private:
  bool dfs(string word, int startIdx)
  {
    // 边界条件
    if (word.size() == startIdx)
      return true;

    Trie *node = trie;
    for (int i = startIdx; i < word.size(); i++)
    {
      int ch = word[i] - 'a';
      node = node->children[ch];
      if (node == nullptr)
        return false;

      // 如果遇到一个单词，就 dfs 的从下一个字符开始继续判断是否为短单词
      if (node->isWord)
        if (dfs(word, i + 1))
          return true;
    }

    return false;
  }

public:
  Trie *trie = new Trie();

  vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
  {
    int n = words.size();
    vector<string> res;

    // 按照字符串长度排序
    sort(words.begin(), words.end(), [&](const string &a, const string &b)
         { return a.size() < b.size(); });

    for (int i = 0; i < words.size(); i++)
    {
      string word = words[i];
      if (word.size() == 0)
        continue;

      if (dfs(word, 0))
        res.emplace_back(word);
      else
        trie->insert(word);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
