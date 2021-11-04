#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution434
{
public:
  int countSegments(string s)
  {
    int n = s.size();
    if (n == 0)
      return 0;

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] != ' ')
      {
        ret++;
        while (i < n && s[i] != ' ')
          i++;
      }
    }

    return ret;
  }
};

int main(void)
{

  return 0;
}
