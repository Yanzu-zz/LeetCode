#include <iostream>
#include <vector>

using namespace std;

class Solution238
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();
    // 左右填充两个 1，这样就不需要再边界特判了
    vector<int> pre(n, 1);  // 前缀乘积数组
    vector<int> post(n, 1); // 后缀乘积数组
    vector<int> res(n, 1);

    // 计算后缀乘积
    post[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
      post[i] = post[i + 1] * nums[i];

    // 计算结果，此时前缀数组一起算
    pre[0] = nums[0];
    for (int i = 1; i < n - 1; i++)
    {
      res[i] = pre[i - 1] * post[i + 1];
      pre[i] = pre[i - 1] * nums[i];
    }

    // 头尾两个元素需要特判
    res[0] = post[1];
    res[n - 1] = pre[n - 2];

    return res;
  }
};

int main(void)
{

  return 0;
}
