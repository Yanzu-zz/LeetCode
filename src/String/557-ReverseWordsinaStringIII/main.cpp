#include <iostream>
#include <vector>

using namespace std;

class Solution557
{
private:
  void reverse(string &s, int i, int j)
  {
    while (i < j)
      swap(s, i++, j--);
  }

  void swap(string &s, int i, int j)
  {
    char ch = s[i];
    s[i] = s[j];
    s[j] = ch;
  }

public:
  string reverseWords(string s)
  {
    int n = s.size();

    // 外层循环寻找空格索引
    int left = 0, right = 0;
    while (right < n)
    {
      // 不是空格的元素忽略掉
      if (s[right] != ' ')
      {
        right++;
        continue;
      }

      // 找到空格了就翻转它
      reverse(s, left, right - 1);

      // 然后更新当前点位值并继续下一轮寻找和翻转
      right++;
      left = right;
    }

    // 因为最后一个 word 后面没有空格，所以我们需要特别操作一下
    reverse(s, left, right - 1);

    return s;
  }
};

int main(void)
{

  return 0;
}
