#include <iostream>
#include <vector>

using namespace std;

class Solution371
{
public:
  int getSum(int a, int b)
  {
    // 这里异或是无进位加法位置，与操作<<1 是进位加法情况
    while (b != 0)
    {
      unsigned int carry = (unsigned int)(a & b) << 1;
      a ^= b;
      b = carry;
    }

    return a;
  }
};

int main(void)
{
  cout << Solution371().getSum(4, 5) << endl;
  cout << Solution371().getSum(11, 22) << endl;

  return 0;
}
