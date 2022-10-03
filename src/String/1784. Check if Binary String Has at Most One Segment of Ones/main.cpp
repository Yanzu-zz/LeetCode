#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool checkOnesSegment(string s)
  {
    int cnt = 0, n = s.size();

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        cnt++;
        while (i < n && s[i++] == '1')
          ;
      }
    }

    return cnt <= 1;
  }
};

int main(void)
{

  return 0;
}
