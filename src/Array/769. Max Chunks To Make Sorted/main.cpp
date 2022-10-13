#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxChunksToSorted(vector<int> &arr)
  {
    int n = arr.size(), res = 0, max = 0;

    for (int i = 0; i < n; i++)
    {
      max = max < arr[i] ? arr[i] : max;
      res += max == i;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
