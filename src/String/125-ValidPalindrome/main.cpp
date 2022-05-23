#include <iostream>
#include <vector>

using namespace std;

class Solution125
{
public:
  bool isPalindrome(string s)
  {
    int n = s.size();
    string pali = "";

    for (char ch : s)
    {
      // Convert ch to lower case character
      if (ch >= 'A' && ch <= 'Z')
        ch += 32;
      if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
        pali += ch;
    }

    int len = pali.size();
    // Then verify this string
    int l = 0, r = len - 1;
    while (l < r)
      if (pali[l++] != pali[r--])
        return false;

    return true;
  }
};

int main(void)
{
  return 0;
}
