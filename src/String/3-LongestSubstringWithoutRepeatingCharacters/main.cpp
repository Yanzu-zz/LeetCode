#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution3
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int n = s.size(), res = 0;
    if (n == 0)
      return res;

    int left = 0, right = 0; // 左右边界指针
    unordered_set<char> se;  // 用来判断滑动窗口下个字符是否已经存在的哈希表
    se.insert(s[0]);

    // 这里 right<n 的原因是处理长度为 1 的字符串
    for (; left < n && right < n; left++)
    {
      // 每次延申时要擦除最左边的一个字符
      if (left > 0)
        se.erase(s[left - 1]);

      // 向右边延申试探最长不重复子串
      while (right < n - 1 && !se.count(s[right + 1]))
        se.insert(s[++right]);

      // 然后每次延申完就看看是不是比当前记录的最长值还长
      res = max(res, right - left + 1);
    }

    return res;
  }
};

int main(void)
{
  string s1 = "pwwkew";
  cout << Solution3().lengthOfLongestSubstring(s1) << endl;

  return 0;
}
