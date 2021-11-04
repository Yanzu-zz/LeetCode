#include <iostream>
#include <vector>

using namespace std;

class Solution461
{
public:
  int hammingDistance(int x, int y)
  {
    // 异或之后，不同的位置是得 1，然后根据系统提供的函数计算有多少位 1 就知道结果了
    return __builtin_popcount(x ^ y);
  }
};

int main(void)
{
  int x1 = 1, y1 = 4;
  cout << Solution461().hammingDistance(x1, y1) << endl;

  return 0;
}
