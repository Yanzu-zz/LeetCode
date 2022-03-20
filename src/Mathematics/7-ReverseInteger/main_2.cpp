#include <iostream>
#include <vector>

using namespace std;

// wrong answer
class Solution7_2
{
private:
  /* Determine whether arguments can be added without overflow */
  int tadd_ok(int x, int y)
  {
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0 && y >= 0 && sum < 0;
    
    return !neg_over && !pos_over;
  }

public:
  int reverse(int x)
  {
    int res = 0;

    while (x != 0)
    {
      int mod = x % 10;
      x /= 10;

      if (!tadd_ok(res * 10, mod))
        return 0;

      res = res * 10 + mod;
    }

    return res;
  }
};

int main(void)
{
  int a = 2147483647;
  cout << Solution7_2().reverse(a) << endl;

  return 0;
}
