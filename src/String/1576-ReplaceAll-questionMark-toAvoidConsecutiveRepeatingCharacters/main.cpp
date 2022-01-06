#include <iostream>
#include <vector>

using namespace std;

class Solution1576
{
public:
  string modifyString(string s)
  {
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
      // 只需要处理问号
      if (s[i] == '?')
      {
        char prev = i > 0 ? s[i - 1] : ' ';
        char next = i < n - 1 ? s[i + 1] : ' ';
        // a-z 的 ASCII 码范围是 97-122
        for (int ch = 97; ch <= 122; ch++)
        {
          if (ch != prev && ch != next)
          {
            s[i] = ch;
            break;
          }
        }
      }
    }

    return s;
  }
};

int main(void)
{
  string s1 = "?zs";
  cout << Solution1576().modifyString(s1) << endl;

  string s2 = "app?eban??iuh?";
  cout << Solution1576().modifyString(s2) << endl;

  string s3 = "???????????????";
  cout << Solution1576().modifyString(s3) << endl;

  string s4 = "";
  cout << Solution1576().modifyString(s4) << endl;

  string s5 = "?peek?";
  cout << Solution1576().modifyString(s5) << endl;

  string s6 = "a?b?c?d?e?z";
  cout << Solution1576().modifyString(s6) << endl;

  return 0;
}
