#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
  int capacity;
  vector<int> heap;

  void swap(int i, int j)
  {
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
  }

public:
  MinHeap(int heapSize)
  {
    this->capacity = heapSize;
  }

  // 添加元素
  void addElement(int val)
  {
    // 如果还没满直接加进去就是了
    if (this->size() < this->capacity)
    {
      heap.emplace_back(val);
      shiftUp(this->size() - 1);
    }
    else
    {
      // 如果满了得话就把最小的元素给剔除（前提是要加入的元素大于它）
      if (val >= this->peek())
      {
        this->heap[0] = val;
        shiftDown(0);
      }
    }
  }

  // 上浮操作（新增元素需要上浮）
  void shiftUp(int elementIdx)
  {
    // 索引从 0 开始的 parent index 求法；
    int parentIdx = (elementIdx + 1) / 2 - 1;
    while (parentIdx >= 0 && heap[elementIdx] < heap[parentIdx])
    {
      swap(elementIdx, parentIdx);
      elementIdx = parentIdx; // 赋值新的索引
      parentIdx = (elementIdx + 1) / 2 - 1;
    }
  }

  void shiftDown(int elementIdx)
  {
    int bounary = this->capacity / 2;
    while (elementIdx < bounary)
    {
      // 索引从 0 开始的 children index 求法
      int base = elementIdx * 2;
      int left = base + 1;
      int right = (base + 2) < this->capacity ? (base + 2) : left; // right 可能会越界
      int direction = heap[left] <= heap[right] ? left : right;

      if (heap[elementIdx] > heap[direction])
      {
        swap(elementIdx, direction);
        elementIdx = direction;
      }
      else
        break;
    }
  }

  int size()
  {
    return this->heap.size();
  }

  int peek()
  {
    if (size() == 0)
      return INT_MIN;

    return this->heap[0];
  }
};

class Solution125_3
{
public:
  // 手撸小根堆
  // 因为是求第 k 大元素，故我们是需要使用小根堆来维护 k 个最大元素（只有当前元素大于堆顶时才能入堆）
  int findKthLargest(vector<int> &nums, int k)
  {
    MinHeap minHeap(k);
    for (int num : nums)
      minHeap.addElement(num);

    return minHeap.peek();
  }
};

int main(void)
{
  vector<int> arr1{3, 2, 1, 5, 6, 4};
  int k1 = 2;
  cout << Solution125_3().findKthLargest(arr1, k1) << endl;

  return 0;
}
