#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution504
{
  // 十进制转 R 进制
  string tenToR(int num, int R)
  {
    if (num == 0)
      return "0";

    // 如果十负数先按照正数的方式转然后返回结果再前面加个负号即可
    bool sign = num < 0 ? 1 : 0;
    if (sign)
      num = -num;

    string res = "";

    while (num > 0)
    {
      int remainder = num % R;
      res.insert(0, to_string(remainder));
      num /= R;
    }

    if (sign)
      res.insert(0, "-");

    return res;
  }

public:
  string convertToBase7(int num)
  {
    return tenToR(num, 7);
  }
};

int main(void)
{
  cout << Solution504().convertToBase7(100) << endl;
  cout << Solution504().convertToBase7(-7) << endl;

  return 0;
}
