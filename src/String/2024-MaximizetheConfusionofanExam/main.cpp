#include <iostream>
#include <vector>

using namespace std;

class Solution2024
{
public:
  int maxConsecutiveChar(string &answerKey, int k, char ch)
  {
    int n = answerKey.length();
    int ans = 0;

    // 滑动窗口
    for (int left = 0, right = 0, sum = 0; right < n; right++)
    {
      // sum 记录的是不同 ch 的值，最多只能替换 k 次
      sum += answerKey[right] != ch;

      // 当不同字符的数量超过 k 时，左指针往右边走
      while (sum > k)
        sum -= answerKey[left++] != ch; // 如果左边指针右移时左元素不为 ch，则表明替换次数可以恢复一次

      // 更新一次最长值
      ans = max(ans, right - left + 1);
    }

    return ans;
  }

  int maxConsecutiveAnswers(string answerKey, int k)
  {
    return max(maxConsecutiveChar(answerKey, k, 'T'),
               maxConsecutiveChar(answerKey, k, 'F'));
  }
};

int main(void)
{

  return 0;
}
