#include <iostream>
#include <vector>

using namespace std;

class Solution735
{
public:
  vector<int> asteroidCollision(vector<int> &asteroids)
  {
    vector<int> res;
    for (int aster : asteroids)
    {
      bool alive = true;
      // 如果遇到了负数行星（向左走）就和栈顶的行星比划比划
      while (alive && aster < 0 && !res.empty() && res.back() > 0)
      {
        alive = res.back() < -aster; // 比划比划
        if (res.back() <= -aster)
          res.pop_back();
      }

      if (alive)
        res.emplace_back(aster);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
