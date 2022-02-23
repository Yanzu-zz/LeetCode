#include <iostream>
#include <vector>

using namespace std;

class Solution917
{
private:
  bool isEnglishWord(string &s, int idx)
  {
    char ch = s[idx];
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
  }

  void swap(string &s, int i, int j)
  {
    char ch = s[i];
    s[i] = s[j];
    s[j] = ch;
  }

public:
  string reverseOnlyLetters(string s)
  {
    int left = 0, right = s.size();

    // 当左指针位置小于右指针时交换才有意义
    while (left < right)
    {
      // 每次交换前都判断一下当前两个指针指向的字符是否为英文字符（大小写都算）
      while (left < right && !isEnglishWord(s, left))
        left++;
      while (right > left && !isEnglishWord(s, right))
        right--;

      // 交换
      swap(s, left++, right--);
    }

    return s;
  }
};

int main(void)
{

  return 0;
}
