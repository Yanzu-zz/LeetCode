#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // 图的边和入度
  unordered_map<char, vector<char>> edges;
  unordered_map<char, int> indegrees;
  // 建图时判断是否有环，可以剪枝
  bool valid = true;

  string alienOrder(vector<string> &words)
  {
    // 先确定好有哪些字母字符出现
    for (auto word : words)
    {
      int len = word.size();
      for (int i = 0; i < len; i++)
      {
        char ch = word[i];
        if (!edges.count(ch))
          edges[ch] = vector<char>();
      }
    }

    // 然后再建图
    int n = words.size();
    for (int i = 1; i < n && valid; i++)
      addEdge(words[i - 1], words[i]);

    // 有环，剪枝
    if (!valid)
      return "";

    // 最后就是拓扑排序了
    queue<char> qu;
    string res;
    // 先初始化入度为 0 的字符
    for (auto [u, _] : edges)
      if (!indegrees.count(u))
        qu.emplace(u);

    while (!qu.empty())
    {
      // 题目保证每次只有一个入度为0的边
      char curr = qu.front();
      qu.pop();
      res += curr;
      // 然后寻找下个入度为 0 的字符
      for (char ch : edges[curr])
      {
        indegrees[ch]--;
        if (indegrees[ch] == 0)
          qu.emplace(ch);
      }
    }

    return res.size() == edges.size() ? res : "";
  }

  // 添加边
  void addEdge(string before, string after)
  {
    // 初始化变量（遍历长度和当前遍历索引）
    int len1 = before.size(), len2 = after.size();
    int len = min(len1, len2);
    int idx = 0;

    while (idx < len)
    {
      char c1 = before[idx], c2 = after[idx];
      // 发现第一个字符不对的时候就有一个入边关系
      if (c1 != c2)
      {
        // 边和入度新加
        edges[c1].emplace_back(c2);
        indegrees[c2]++;
        break; // 可以剪枝了
      }
      idx++; // 否则继续遍历下去
    }

    // 若有 [“a",“b",“a"]，[“ab",“a"] 这两种情况则表明有环，直接 false
    if (idx == len && len1 > len2)
      valid = false;
  }
};

int main()
{

  return 0;
}