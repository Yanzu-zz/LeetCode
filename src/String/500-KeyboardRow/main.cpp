#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution500
{
public:
  vector<string> findWords(vector<string> &words)
  {
    vector<string> res;
    string rowIdx = "12210111011122000010020202"; // 每一个英文字母标记其对应键盘上的行号

    for (const auto &word : words)
    {
      bool isValid = true;
      // 获取首个字符的 行号
      int currRowIdx = rowIdx[tolower(word[0]) - 'a'];
      for (int i = 1; i < word.size(); i++)
      {
        if (rowIdx[tolower(word[i]) - 'a'] != currRowIdx)
        {
          isValid = false;
          break;
        }
      }

      if (isValid) // 如果都是同一行就加进来
        res.push_back(word);
    }

    return res;
  }
};

int main()
{

  return 0;
}