#include <iostream>
#include <vector>

using namespace std;

class Solution553
{
public:
  /**
   * 你以为考的是算法，实际上考的是字符处理，用脑筋急转弯包装了一层而已。
   * 如果想要结果最大，那么实际就是要第二个数要最小，那么第一个数除以最小的第二个数，
   * 才会获得最大结果，而第二个数一直往后除那就是最小值。
   */
  string optimalDivision(vector<int> &nums)
  {
    int n = nums.size();
    string res;
    // 先把第一个数加入数组
    res.append(to_string(nums[0]));

    if (n == 1)
    {
      return res;
    }

    // 第二个到最后元素有个括号）
    res.append("/");
    if (n == 2)
    {
      res.append(to_string(nums[1]));
    }
    else
    {

      res.append("(");
      // 然后就是处理后面的每个元素了
      for (int i = 1; i < n; i++)
      {
        res.append(to_string(nums[i]));
        // 最后一个数字不需要加除号
        if (i != n - 1)
          res.append("/");
      }

      // 到了最后要补上一个右括号 )
      res.append(")");
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
