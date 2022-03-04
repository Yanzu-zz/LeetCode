#include <iostream>
#include <vector>

using namespace std;

class Solution238_2
{
public:
  // 左右乘积做法，核心是利用区间对称，即 f(x) 对称的是 f(a+b-x)
  // 这里的 a 是 0，b 为 n，x 为 i，又因为是数组，故我们需要再 -1
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();
    int left = 1, right = 1;
    vector<int> res(n, 1);

    // 这样写的话前半个区间和后半个区间都会再次计算
    for (int i = 0; i < n; i++)
    {
      // 这里先乘上左区间的乘积
      res[i] *= left;
      left *= nums[i]; // 继续累乘区间乘积

      // 这里补上右区间的乘积
      res[n - 1 - i] *= right;
      right *= nums[n - 1 - i]; // 右乘积
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
