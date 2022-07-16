#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MovingAverage
{
public:
  int maxSize = 0;
  double currSum = 0;
  queue<int> qu;

  /** Initialize your data structure here. */
  MovingAverage(int size) : maxSize(size)
  {
  }

  double next(int val)
  {
    // 如果窗口满了
    if (qu.size() >= maxSize)
    {
      currSum -= qu.front();
      qu.pop();
    }

    currSum += val;
    qu.emplace(val);
    return currSum / qu.size();
  }
};

int main(void)
{

  return 0;
}
