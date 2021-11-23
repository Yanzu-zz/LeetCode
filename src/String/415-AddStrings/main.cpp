#include <iostream>
#include <vector>

using namespace std;

class Solution415
{
public:
  string addStrings(string num1, string num2)
  {
    int n = num1.size(), m = num2.size();
    int i = n - 1, j = m - 1, carry = 0; // 字符串1,2 的位置指针，carry 为进位值
    string res = "";

    while (i >= 0 || j >= 0 || carry > 0)
    {
      // 因为两个字符串的长度有可能不同，所以这样获得当前位置的值就有保证相加的值是对的
      int a = i >= 0 ? (num1[i] - '0') : 0;
      int b = j >= 0 ? (num2[j] - '0') : 0;
      // 每次相加都要带上进位值（如果没进位就是0，对结果没有影响）
      int result = a + b + carry;
      carry = result / 10; // 获取当前是否有进位

      // 将当前轮次的结果存入 res 中
      res.push_back('0' + result % 10); // 因为题目要求说了不能用stl库自带的字符串转换函数，故我们这里就利用 ascii 码的特性进行转化即可

      // 然后维护两个指针的位置
      i--;
      j--;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};

int main()
{

  return 0;
}