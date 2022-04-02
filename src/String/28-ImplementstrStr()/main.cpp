#include <iostream>
#include <vector>

using namespace std;

class Solution28
{
public:
  int strStr(string haystack, string needle)
  {
    int n = haystack.size(), m = needle.size();

    int i = 0;
    for (; i <= n - m; i++)
    {
      // 暴力逐个判断
      int j = 0;
      for (; j < m; j++)
        if (needle[j] != haystack[i + j])
          break;

      if (j == m)
        return i;
    }

    return -1;
  }
};

int main(void)
{

  return 0;
}
