#include <iostream>
#include <vector>

using namespace std;

/**
 * N=1 和 N = 2N=2 时结论成立。
 * N > 2N>2 时，假设 N \leq kN≤k 时该结论成立，则 N = k + 1N=k+1 时：
 * 如果 kk 为偶数，则 k + 1k+1 为奇数，xx 是 k + 1k+1 的因数，只可能是奇数，而奇数减去奇数等于偶数，且 k + 1 - x \leq kk+1−x≤k，故轮到 \text{Bob}Bob 的时候都是偶数。而根据我们的猜想假设 N\le kN≤k 的时候偶数的时候先手必胜，故此时无论 \text{Alice}Alice 拿走什么，\text{Bob}Bob 都会处于必胜态，所以 \text{Alice}Alice 处于必败态。
 * 如果 kk 为奇数，则 k + 1k+1 为偶数，xx 可以是奇数也可以是偶数，若 \text{Alice}Alice 减去一个奇数，那么 k + 1 - xk+1−x 是一个小于等于 kk 的奇数，此时 \text{Bob}Bob 占有它，处于必败态，则 \text{Alice}Alice 处于必胜态。
 */
class Solution1025
{
public:
  bool divisorGame(int n)
  {
    return n % 2 == 0;
  }
};

int main(void)
{

  return 0;
}
