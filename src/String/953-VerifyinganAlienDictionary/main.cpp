#include <iostream>
#include <vector>

using namespace std;

class Solution953
{
public:
  bool isAlienSorted(vector<string> &words, string order)
  {
    int dict[26] = {0};
    for (int i = 0; i < 26; i++)
      dict[order[i] - 'a'] = i; // 记录字典序顺序

    // 暴力验证顺序是否正确
    int n = words.size();
    for (int i = 1; i < n; i++)
    {
      int currLen = words[i].size(), prevLen = words[i - 1].size();
      int len = currLen > prevLen ? prevLen : currLen;

      bool isValid = false;
      for (int j = 0; j < len; j++)
      {
        int currIdx = dict[words[i][j] - 'a'], prevIdx = dict[words[i - 1][j] - 'a'];
        if (prevIdx > currIdx)
          return false;
        else if (prevIdx < currIdx)
        {
          isValid = true;
          break;
        }
      }

      // 如果字典序正确，但是可能出现 apple, app 这样的情况，需要判断长度
      if (!isValid && prevLen > currLen)
        return false;
    }

    return true;
  }
};

int main(void)
{
  vector<string> arr1 = {"hello", "leetcode"};
  cout << Solution953().isAlienSorted(arr1, "hlabcdefgijkmnopqrstuvwxyz") << endl;

  return 0;
}
