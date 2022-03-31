#include <iostream>
#include <vector>

using namespace std;

class Solution728
{
private:
  bool isSelfDividingNumber(int i)
  {
    int num = i;
    while (num)
    {
      int remainder = num % 10;
      // 如果有个数字位为 0 或者 不能整除这个数位，则表明不是 self divident number
      if (remainder == 0 || i % remainder != 0)
        return false;

      num /= 10;
    }

    return true;
  }

public:
  vector<int> selfDividingNumbers(int left, int right)
  {
    // 暴力验证每个数字
    vector<int> res;

    for (int i = left; i <= right; i++)
    {
      if (isSelfDividingNumber(i))
        res.emplace_back(i);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
