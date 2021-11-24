#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution43
{
private:
  // 详看 415 题
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

public:
  /**
    * 计算形式
    *    num1
    *  x num2
    *  ------
    *  result
    */
  string multiply(string num1, string num2)
  {
    if (num1 == "0" || num2 == "0")
      return "0";
    int n = num1.size(), m = num2.size();
    string res = "0";

    for (int j = m - 1; j >= 0; j--)
    {
      int carry = 0, num2Val = num2[j] - '0';
      string temp = "";
      // 补0
      for (int zero = 0; zero < m - 1 - j; zero++)
        temp.push_back('0');

      // 开始用当前 num2 的位置的值与 num1 相乘
      // 注意，这里可能最前面有进位，但此时 i 小于 0了，循环不运行，故我们需要特判 进位标志是否还存在
      for (int i = n - 1; i >= 0 || carry > 0; i--)
      {
        // 因为 i 可能小于0时 carry进位还存在，故这里需要这样获得值
        int num1Val = i >= 0 ? num1[i] - '0' : 0;
        int result = num1Val * num2Val + carry;
        // 当前位置只需要添加余数
        temp.push_back('0' + result % 10); // c++ 添加字符串最好用 push_back
        // 而进位可能是 9*9=81，可以 +8
        carry = result / 10;
      }

      // 这里也要翻转
      reverse(temp.begin(), temp.end());
      res = addStrings(res, temp);
    }

    return res;
  }
};

int main()
{
  string a1 = "6", b1 = "10";
  cout << Solution43().multiply(a1, b1) << endl;

  string a2 = "0", b2 = "0";
  cout << Solution43().multiply(a2, b2) << endl;

  string a3 = "8", b3 = "9";
  cout << Solution43().multiply(a3, b3) << endl;

  return 0;
}