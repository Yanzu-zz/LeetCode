#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 前缀树节点
struct TrieNode
{
  int val;
  TrieNode *next[26];

  TrieNode()
  {
    this->val = 0;
    for (int i = 0; i < 26; i++)
      this->next[i] = nullptr;
  }
};

class MapSum
{
private:
  TrieNode *root;
  unordered_map<string, int> cnt;

public:
  MapSum()
  {
    // 初始化前缀树
    this->root = new TrieNode();
  }

  // 前缀树的插入方式
  void insert(string key, int val)
  {
    int delta = val;

    // 这个判断是计算出新值与旧值的差别，然后下面就会逐个节点更新
    // 如 1：['apple', 5]，则第二次 ['apple', 3] 的差别就是 -2，所有这个前缀的节点值都会 -= 2
    // 之所以不能直接 赋val 的值是因为后面可能还会有相同前缀的和，故不能直接简单赋值，要动态减少增加差值 ^_^
    if (cnt.count(key))
      delta -= cnt[key];
    cnt[key] = val;

    // 下面就是典型的 Trie 插入值的代码了
    TrieNode *node = root;
    for (const auto &c : key)
    {
      // 没节点就创建新节点
      if (node->next[c - 'a'] == nullptr)
        node->next[c - 'a'] = new TrieNode();

      // 跳到下个节点并且动态增减
      node = node->next[c - 'a'];
      node->val += delta;
    }
  }

  // 和插入的代码差不多，只不过这里不动态增减
  int sum(string prefix)
  {
    TrieNode *node = root;
    for (const auto &c : prefix)
    {
      if (node->next[c - 'a'] == nullptr)
        return 0;

      node = node->next[c - 'a'];
    }

    return node->val;
  }
};

int main()
{

  return 0;
}