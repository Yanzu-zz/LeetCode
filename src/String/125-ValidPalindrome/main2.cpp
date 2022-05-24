#include <iostream>
#include <vector>

using namespace std;

class Solution125
{
public:
  bool isValid(char ch)
  {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
  }

  bool isPalindrome(string s)
  {
    int n = s.size();
    int l = 0, r = n - 1;

    while (l < r)
    {
      // first move to the next valid character
      while (l < r && !isValid(s[l]))
        l++;
      while (r > l && !isValid(s[r]))
        r--;
      if (l >= r)
        return true;

      // Then verify them
      char chL = s[l], chR = s[r];
      if (chL >= 'A' && chL <= 'Z')
        chL += 32;
      if (chR >= 'A' && chR <= 'Z')
        chR += 32;

      if (chL != chR)
        return false;

      l++;
      r--;
    }

    return true;
  }
};

int main(void)
{
  return 0;
}
