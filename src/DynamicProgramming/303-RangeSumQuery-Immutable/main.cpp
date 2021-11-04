#include <iostream>
#include <vector>

using namespace std;

/**
 * 解决思路：前缀和
 * 因为题目说了不变，故我们在初始化时维护一个前缀和数组
 * 计算时返回 qzh[right-1] - qzh[left-1] 即可
 */
class NumArray
{
private:
  vector<int> preSum;

public:
  NumArray(vector<int> &nums)
  {
    int n = nums.size();
    preSum = vector<int>(n + 1);
    preSum[0] = 0;
    for (int i = 1; i <= n; i++)
      preSum[i] = preSum[i - 1] + nums[i - 1];
  }

  int sumRange(int left, int right)
  {
    return preSum[right + 1] - preSum[left];
  }
};

int main(void)
{
  vector<int> arr1 = {-2, 0, 3, -5, 2, -1};
  NumArray *num1 = new NumArray(arr1);
  cout << num1->sumRange(0, 2) << endl;
  cout << num1->sumRange(2, 5) << endl;
  cout << num1->sumRange(0, 5) << endl;

  return 0;
}
