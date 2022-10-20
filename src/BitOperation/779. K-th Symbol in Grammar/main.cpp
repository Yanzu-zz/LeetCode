#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int kthGrammar(int n, int k)
  {
    // 经过观察发现这道题的解其实就是对 k-1 进行了一个奇偶校验
    k--;
    k ^= k >> 1;
    k ^= k >> 2;
    k = (k & 0x11111111U) * 0x11111111U;
    return (k >> 28) & 1;
  }
};

int main(void)
{

  return 0;
}
