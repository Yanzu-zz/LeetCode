#include <iostream>
#include <vector>

using namespace std;

// 树状数组忘了的话看笔记
class NumArray
{
private:
  vector<int> A; // 原数组
  vector<int> C; // 树状数组

  int lowbit(int x)
  {
    return x & (-x);
  }

  void add(int index, int val)
  {
    // 作差，这样方便让父节点都加上这个值
    int d = val - A[index];

    // 更新原数组 index 处的值，题目要求的
    A[index] = val;

    // 然后更新各父节点的值
    int n = C.size();
    // 找到最后一个 1 所在结点，然后用lowBit函数依次自下而上更新其所有父结点
    for (int i = index + 1; i < n; i += lowbit(i))
      C[i] += d;
  }

  // 求 [0...index] 的区间和
  int preSum(int index)
  {
    int sum = 0;

    // 找到 index 所在结点，用lowBit函数不断消去最后一个位 1，并进行累加
    for (int i = index; i >= 1; i -= lowbit(i))
      sum += C[i];

    return sum;
  }

public:
  NumArray(vector<int> &nums) : A(nums)
  {
    int n = A.size();

    // 构造树状数组
    C = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      C[i] += A[i - 1];
      // 父节点要加上子节点的值
      if (i + lowbit(i) <= n)
        C[i + lowbit(i)] += C[i];
    }
  }

  void update(int index, int val)
  {
    add(index, val);
  }

  int sumRange(int left, int right)
  {
    int leftSum = preSum(left);
    int rightSum = preSum(right + 1);

    // 减去 [0...left] 和 [0...left...right] 中重合的地方即 [0...left]
    return rightSum - leftSum;
  }
};

int main(void)
{

  return 0;
}
