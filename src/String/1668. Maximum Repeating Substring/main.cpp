#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
  int maxRepeating(string sequence, string word)
  {
    int res = 0, maxCnt = 0;
    int n = sequence.size(), m = word.size();

    int i = 0;
    while (i < n)
    {
      int curr = i;
      int j = 0;
      while (curr < n && j < m && sequence[curr] == word[j])
      {
        curr++;
        j++;
      }

      if (j == m)
      {
        res++;
        maxCnt = res > maxCnt ? res : maxCnt;
        i += m;
      }
      else
      {
        res = 0;
        i++;
      }
    }

    return maxCnt;
  }
};

int main(void)
{
  string s1 = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
  string s2 = "aaaba";

  Solution().maxRepeating(s1, s2);

  return 0;
}
