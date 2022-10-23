#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    string res = "";
    int len1 = word1.size(), len2 = word2.size();
    int n = min(len1, len2) << 1;

    int idx1 = 0, idx2 = 0;

    for (int i = 0; i < n; i++)
    {
      if (i % 2 == 0)
        res += word1[idx1++];
      else
        res += word2[idx2++];
    }

    if (len1 < len2)
    {
      for (int i = len1; i < len2; i++)
        res += word2[i];
    }
    else
    {
      for (int i = len2; i < len1; i++)
        res += word1[i];
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
