#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution318
{
public:
  int maxProduct(vector<string> &words)
  {
    int n = words.size();
    bool alphabet[26] = {false};
    int res = 0;

    for (int i = 0; i < n; i++)
    {
      // 先将当前字符串出现的字母记录下来
      for (const auto &word : words[i])
        alphabet[word - 'a'] = true;

      // 然后暴力扫描后面的字符串
      for (int j = i + 1; j < n; j++)
      {
        bool isValid = true;
        // 如果包含同样的字母，则剪枝，不用理这个字符串了
        for (const auto &word : words[j])
        {
          if (alphabet[word - 'a'])
          {
            isValid = false;
            break;
          }
        }

        // 否则当前是个合格的对比字符串
        if (isValid)
          res = max(res, int(words[i].size() * words[j].size()));
      }

      // 最后把字符串出现的字母记录删除
      memset(alphabet, false, sizeof(alphabet));
      // for (const auto &word : words[i])
      //alphabet[word - 'a'] = false;
    }

    return res;
  }
};

int main()
{
  vector<string> strs1 = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  cout << Solution318().maxProduct(strs1) << endl;

  vector<string> strs2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  cout << Solution318().maxProduct(strs2) << endl;

  return 0;
}