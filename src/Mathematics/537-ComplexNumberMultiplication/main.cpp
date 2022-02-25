#include <iostream>
#include <vector>

using namespace std;

class Solution537
{
private:
  // 找到 + 号在字符串中的位置好提取 a b c d
  int findPlusPos(string str)
  {
    int n = str.size();

    int i = 0;
    for (; i < n && str[i] != '+'; i++)
      ;

    return i == n ? -1 : i;
  }

public:
  string complexNumberMultiply(string num1, string num2)
  {
    int a, b, c, d;
    // 各自的 + 号索引
    int num1PlusPos = findPlusPos(num1);
    int num2PlusPos = findPlusPos(num2);

    // 开始提取关键数字
    a = atoi(num1.substr(0, num1PlusPos).c_str());
    b = atoi(num1.substr(num1PlusPos + 1, num1.size() - num1PlusPos + 2).c_str()); // +2 是为了去掉末尾的 i
    c = atoi(num2.substr(0, num2PlusPos).c_str());
    d = atoi(num2.substr(num2PlusPos + 1, num2.size() - num2PlusPos + 2).c_str());

    // 提取完 4 个关键数字后就用数学公式 (ac - bd) + (ad + cb)i 计算即可
    int z1 = a * c - b * d;
    int z2 = a * d + c * b;

    // 转为题目需要的字符串格式
    string res;
    res.append(to_string(z1));
    res.append("+");
    res.append(to_string(z2));
    res.append("i");

    return res;
  }
};

int main(void)
{
  string num1 = "1+1i", num2 = "1+1i";
  cout << Solution537().complexNumberMultiply(num1, num2) << endl;

  string num3 = "-1+1i", num4 = "1+-1i";
  cout << Solution537().complexNumberMultiply(num3, num4) << endl;

  string num5 = "-100+100i", num6 = "100+100i";
  cout << Solution537().complexNumberMultiply(num5, num6) << endl;

  return 0;
}
