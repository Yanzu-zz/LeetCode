#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class RecentCounter
{
private:
  queue<int> qu;

public:
  RecentCounter()
  {
    // We push an unreachable element to unify the operation
    qu.emplace(-4001);
  }

  int ping(int t)
  {
    // Once the front element of queue outrange the [t-3000, t], then we pop it
    while (qu.size() > 0 && qu.front() < t - 3000)
      qu.pop();
    qu.emplace(t);

    return qu.size();
  }
};

int main(void)
{

  return 0;
}
