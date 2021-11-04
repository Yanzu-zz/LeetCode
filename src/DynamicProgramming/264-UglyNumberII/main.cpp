#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

/**
  要得到从小到大的第 n 个丑数，可以使用最小堆实现。
  初始时堆为空。首先将最小的丑数 1 加入堆。
  每次取出堆顶元素 x，则 x 是堆中最小的丑数，由于 2x, 3x, 5x 也是丑数，因此将 2x, 3x, 5x 加入堆。
  上述做法会导致堆中出现重复元素的情况。为了避免重复元素，可以使用哈希集合去重，避免相同元素多次加入堆。
  在排除重复元素的情况下，第 n 次从最小堆中取出的元素即为第 n 个丑数。
 */
class Solution264
{
public:
  int nthUglyNumber(int n)
  {
    vector<int> factors = {2, 3, 5};
    unordered_set<int> stored;
    priority_queue<long, vector<long>, greater<long>> heap;
    stored.insert(1L);
    heap.push(1L);

    int ret = 0;
    long next;
    // 下面就是根据我们的定义来实现代码了
    for (int i = 0; i < n; i++)
    {
      long curr = heap.top();
      heap.pop();
      ret = (int)curr;

      for (int factor : factors)
      {
        next = curr * factor;
        if (!stored.count(next))
        {
          stored.insert(next);
          heap.push(next);
        }
      }
    }

    return ret;
  }
};

int main(void)
{
  int n1 = 10;
  int n2 = 1;
  int n3 = 20;

  cout << Solution264().nthUglyNumber(n1) << endl;
  cout << Solution264().nthUglyNumber(n2) << endl;
  cout << Solution264().nthUglyNumber(n3) << endl;

  return 0;
}
