#include <iostream>
#include <vector>

using namespace std;

class Solution717
{
public:
  bool isOneBitCharacter(vector<int> &bits)
  {
    int n = bits.size(), idx = 0;
    while (idx < n - 1)
    {
      // 遇到 0 则往后走一步，遇到 1 则肯定是要走两步的
      if (bits[idx] == 0)
        idx++;
      else
        idx += 2;
    }

    return idx == n - 1;
  }
};

int main(void)
{

  return 0;
}
