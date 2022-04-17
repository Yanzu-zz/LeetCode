#include <iostream>
#include <vector>
#include <unordered_map>

#define BANNED -10086

using namespace std;

class Solution819
{
private:
  bool isAlphabet(string &str, int idx)
  {
    char ch = tolower(str[idx]);
    return ch >= 'a' && ch <= 'z';
  }

  char tolower(char ch)
  {
    // 转小写
    if (ch >= 'A' && ch <= 'Z')
      return ch + 32;

    return ch;
  }

public:
  string mostCommonWord(string paragraph, vector<string> &banned)
  {
    int n = paragraph.size();
    int maxCnt = 0;
    string res = "";
    unordered_map<string, int> mp;

    // 先给 banned word 记录在哈希表中
    int m = banned.size();
    for (int i = 0; i < m; i++)
      mp[banned[i]] = BANNED; // -1 表示 banned

    // 然后就是正式遍历字符串了
    for (int i = 0; i < n;)
    {
      // 如果新一轮循环的开头不是 word，则往后面走
      if (!isAlphabet(paragraph, i))
      {
        i++;
        continue;
      }

      // 找到当前这个 word
      int j = i + 1;
      for (; j < n && isAlphabet(paragraph, j); j++)
        ;

      // 然后获取当前这个 word
      string tmp = paragraph.substr(i, j - i);
      // 转小写
      int len = tmp.size();
      for (int k = 0; k < len; k++)
        tmp[k] = tolower(tmp[k]);

      // 存入哈希表中（非 banned word 才行）
      if (mp[tmp] != BANNED)
      {
        mp[tmp]++;
        // 同时更新最大值
        if (mp[tmp] > maxCnt)
        {
          maxCnt = mp[tmp];
          res = tmp;
        }
      }

      // 接着到下个 word 开头
      i = j + 1;
    }

    return res;
  }
};

int main(void)
{

  string str1 = "Bob hit a ball, the hit BALL flew far after it was hit.";
  vector<string> arr1 = {"hit"};
  cout << Solution819().mostCommonWord(str1, arr1) << endl;

  return 0;
}
