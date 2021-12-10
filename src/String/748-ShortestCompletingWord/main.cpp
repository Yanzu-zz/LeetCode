#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution748
{
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words)
  {
    int n = words.size(), idx = -1;
    int pCnt[26] = {0};

    // 统计 licensePlate 出现的字符个数
    // 需要判定是否为数组且忽略大小写
    for (auto &ch : licensePlate)
      if (isalpha(ch))
        pCnt[tolower(ch) - 'a']++;

    // 接下来就是和 words 里面的字符串对比寻找最佳补全词了
    for (int i = 0; i < n; i++)
    {
      string word = words[i];
      int wCnt[26] = {0};
      // 统计当前单词的词频，words 数组里面的都是字母，故不用判定
      for (auto &ch : word)
        wCnt[tolower(ch) - 'a']++;

      // 逐个字符对比查看，若当前字符串比 licensePlate 少了一个字符，则舍去当前字符串（因为不能有任何不同的单词出现）
      // 原因是 licensePlate 是要找到的补全词的子集
      bool isValid = true;
      for (int i = 0; i < 26; i++)
      {
        if (pCnt[i] > wCnt[i])
        {
          isValid = false;
          break;
        }
      }

      // 如果当前字符串包含 licensePlate，且当前字符串长度小于之前记录的包含字符串，则更新最短补全词索引
      if (isValid && (idx < 0 || word.size() < words[idx].size()))
        idx = i; // 返回的是索引
    }

    return words[idx];
  }
};

int main(void)
{

  return 0;
}
