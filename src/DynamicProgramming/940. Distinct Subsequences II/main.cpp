#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int distinctSubseqII(string s)
  {
    int MOD = 1e9 + 7;
    int n = s.size();
    vector<long int> arr(26); // 26 个单词

    // 用一个数组存储26个字母结尾的字符串数量
    // 每往后读一个就把整个数组全加起来再加一更新对应字母结尾的数组
    for (int i = 0; i < n; i++)
    {
      long int sum = 0;
      for (int j = 0; j < 26; j++)
        sum = (sum + arr[j]) % MOD;

      arr[s[i] - 'a'] = sum + 1;
    }

    long res = 0;
    for (int i = 0; i < 26; i++)
      res = (res + arr[i]) % MOD;

    return res;
  }
};

int main(void)
{

  return 0;
}
