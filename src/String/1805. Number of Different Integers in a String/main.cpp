#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int numDifferentIntegers(string word)
  {
    int n = word.size(), res = 0;
    unordered_map<string, int> mp;

    int i = 0;
    while (i < n)
    {
      int j = i;
      if (word[j] >= '0' && word[j] <= '9')
      {
        // 如果是前导零，直接拒绝掉
        while (j < n && word[j] == '0')
          j++;

        i = j;
        // 开始截取数字
        while (j < n && word[j] >= '0' && word[j] <= '9')
          j++;

        string cnt = word.substr(i, j - i);

        if (mp[cnt] == 0)
        {
          res++;
          mp[cnt]++;
        }
      }
      
      i = j;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
