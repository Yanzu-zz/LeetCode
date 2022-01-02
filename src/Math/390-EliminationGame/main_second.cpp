#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int lastRemaining(int n)
  {
    return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
  }
};

int main(void)
{

  return 0;
}
