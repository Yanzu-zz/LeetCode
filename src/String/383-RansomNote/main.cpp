#include <iostream>
#include <vector>

using namespace std;

class Solution383
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    int n = ransomNote.size(), m = magazine.size();
    int chCnt[26] = {0};

    // 统计 magazine 词源字符个数
    for (const auto &ch : magazine)
      chCnt[ch - 'a']++;

    // 验证 rasomNote 是否能写出来
    for (const auto &ch : ransomNote)
    {
      if (chCnt[ch - 'a'] == 0)
        return false;
      chCnt[ch - 'a']--;
    }

    return true;
  }
};

int main()
{

  return 0;
}