#include <iostream>
#include <vector>

using namespace std;

class Solution_Sword69
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int n = arr.size();
    int maxVal = arr[0], peekIdx = 0;
    for (int i = 1; i < n; i++)
    {
      if (arr[i] > maxVal)
      {
        maxVal = arr[i];
        peekIdx = i;
      }
    }

    return peekIdx;
  }
};

int main(void)
{

  return 0;
}
