#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution306
{
private:
  // 大数加法模板
  string add(string &a, string &b)
  {
    string res;
    int n1 = a.size() - 1;
    int n2 = b.size() - 1;
    int carry = 0; // 进位占位符

    // 开始计算，这很直观了吧，之前也做过这题
    while (n1 >= 0 || n2 >= 0 || carry > 0)
    {
      int t1 = n1 >= 0 ? a[n1--] - '0' : 0;
      int t2 = n2 >= 0 ? b[n2--] - '0' : 0;

      res += (t1 + t2 + carry) % 10 + '0';
      carry = (t1 + t2 + carry) / 10;
    }

    // 最后要翻转一下字符串
    reverse(res.begin(), res.end());
    return res;
  }

  // num1: [i, j) + num2: [j, k) = sum: [k, ...)
  bool dfs(string &num, int i, int j, int k)
  {
    // 剪枝
    if (num[i] == '0' && j != i + 1)
      return false;
    if (num[j] == '0' && k != j + 1)
      return false;

    // 获取当前轮次需要验证的两个数字
    string a = num.substr(i, j - i);
    string b = num.substr(j, k - j);

    string sum = add(a, b);
    int n = num.size(), m = sum.size();
    // 越界剪枝
    if (m + k > n)
      return false;

    // 以当前选定的前两个数对第三个数进行验证
    for (int s = k; s <= k - 1 + m; s++)
      if (num[s] != sum[s - k])
        return false;

    // 最终验证到长度相等则说明符合则当前字符串是一个累加数
    if (m + k == n)
      return true;

    // 继续试验后面的新的字符串是否符合累加数定义
    return dfs(num, j, k, m + k);
  }

public:
  bool isAdditiveNumber(string num)
  {
    int n = num.size();

    // 开始爆搜
    for (int i = 1; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (dfs(num, 0, i, j))
          return true;

    return false;
  }
};

int main(void)
{

  return 0;
}
