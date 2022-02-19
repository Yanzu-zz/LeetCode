#include <iostream>
#include <vector>

using namespace std;

class Solution969
{
private:
  // 寻找当前 第 i 大的数字索引，因为数组是 1-maximum 组合的，故我们很好操作
  // 注意哦，返回的是索引
  int find_i(vector<int> &arr, int num)
  {
    int n = arr.size();
    for (int i = 0; i < n; i++)
      if (arr[i] == num)
        return i;

    return 0;
  }

  // 翻转数组
  void reverse(vector<int> &arr, int end)
  {
    int front = 0, rear = end, temp = 0;
    while (front < rear)
    {
      temp = arr[front];
      arr[front++] = arr[rear];
      arr[rear--] = temp;
    }
  }

public:
  vector<int> pancakeSort(vector<int> &arr)
  {
    vector<int> res;

    // 每次找到最大值所在的 idx，接着翻转 arr[0,idx]，然后整个数组翻转，此时当前轮次的最大值已经确定，arr数组调整范围-1
    int curMaxNum = arr.size();
    while (curMaxNum > 1)
    {
      // 找当前轮次的最大值的索引
      int tmpMax = find_i(arr, curMaxNum);
      // 翻转 0-索引 的顺序
      reverse(arr, tmpMax);
      res.emplace_back(tmpMax + 1); // 记录操作
      // 翻转整个数组（未确定的范围）
      reverse(arr, curMaxNum - 1);
      res.emplace_back(curMaxNum); // 记录操作

      // 最后扩大数组排序确定范围
      curMaxNum--;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
