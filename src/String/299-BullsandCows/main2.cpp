#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int countSubstrings(string s)
  {
    int n = s.size(), res = 0;
    for (int center = 0; center < 2 * n - 1; center++)
    {
      // left和right指针和中心点的关系是？
      // 首先是left，有一个很明显的2倍关系的存在，其次是right，可能和left指向同一个（偶数时），也可能往后移动一个（奇数）
      // 大致的关系出来了，可以选择带两个特殊例子进去看看是否满足。
      int left = center / 2;
      int right = left + center % 2;

      // 开始中心扩展
      while (left >= 0 && right < n && s[left] == s[right])
      {
        res++;
        left--;
        right++;
      }
    }

    return res;
  }
};

int main()
{

  return 0;
}