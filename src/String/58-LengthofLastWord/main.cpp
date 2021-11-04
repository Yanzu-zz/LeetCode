#include <iostream>
#include <vector>

using namespace std;


class Solution58
{
public:
  int lengthOfLastWord(string s)
  {
    int n = s.size();
    int lastWordFrontIndex = -1, lastWordRearIndex = n;

    // finding the first non-space character from back to front
    for (int i = n - 1; i >= 0; i--)
    {
      if (s[i] != ' ')
      {
        lastWordRearIndex = i;
        break;
      }
    }

    // then search the second space char
    for (int i = lastWordRearIndex - 1; i >= 0; i--)
    {
      if (s[i] == ' ')
      {
        lastWordFrontIndex = i;
        break;
      }
    }

    return lastWordRearIndex - lastWordFrontIndex;
  }
};

int main(void)
{
  string s1 = "abcde";
  string s2 = " abcde";
  string s3 = "an apple";
  string s4 = "extremelycold";
  string s5 = "     this sdlnf jsadhf dfj krgh    ";

  cout << Solution58().lengthOfLastWord(s1) << endl;
  cout << Solution58().lengthOfLastWord(s2) << endl;
  cout << Solution58().lengthOfLastWord(s3) << endl;
  cout << Solution58().lengthOfLastWord(s4) << endl;
  cout << Solution58().lengthOfLastWord(s5) << endl;

  return 0;
}
