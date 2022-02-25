#include <iostream>
#include <vector>

using namespace std;

class Solution367
{
public:
  bool isPerfectSquare(int num)
  {
    long i = 1, square = 1;
    for (; square <= num; i++)
    {
      square = i * i;
      if (square == num)
        return true;
    }

    return false;
  }
};

int main()
{

  return 0;
}