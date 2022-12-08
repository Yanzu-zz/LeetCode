#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
  bool squareIsWhite(string coordinates)
  {
    return ((coordinates[0] - 'a') + (coordinates[1] - '1')) & 1;
  }
};

int main(void)
{

  return 0;
}
