#include <iostream>
#include <vector>

using namespace std;

/**
 * Wrong Answer!!!
 */
class Solution2024
{
public:
  int maxConsecutiveAnswers(string answerKey, int k)
  {
    int n = answerKey.size();
    int res = 1;

    // 从左到右
    for (int i = 0; i < n; i++)
    {
      // 跳过和上一个字符相同的位置
      if (i > 0 && answerKey[i] == answerKey[i - 1])
        continue;

      int j, cnt = 1, tmpK = k;
      for (j = i + 1; j < n && tmpK >= 0; j++)
      {
        if (answerKey[j] == answerKey[i])
        {
          cnt++;
        }
        else if (answerKey[j] != answerKey[i] && tmpK > 0)
        {
          tmpK--;
          cnt++;
        }
        else
        {
          break;
        }
      }

      // 更新最大长度（如果可以）
      res = max(res, cnt);

      // 剪枝
      if (j >= n)
        break;
    }

    // 从右到左
    for (int i = n - 1; i >= 0; i--)
    {
      // 跳过和上一个字符相同的位置
      if (i < n - 1 && answerKey[i] == answerKey[i + 1])
        continue;

      int j, cnt = 1, tmpK = k;
      for (j = i - 1; j >= 0 && tmpK >= 0; j--)
      {
        if (answerKey[j] == answerKey[i])
        {
          cnt++;
        }
        else if (answerKey[j] != answerKey[i] && tmpK > 0)
        {
          tmpK--;
          cnt++;
        }
        else
        {
          break;
        }
      }

      // 更新最大长度（如果可以）
      res = max(res, cnt);

      // 剪枝 
      if (j < 0)
        break;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
