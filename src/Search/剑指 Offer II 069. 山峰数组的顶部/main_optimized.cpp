#include <iostream>
#include <vector>

using namespace std;

class Solution_Sword69
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int n = arr.size();
    int mid = n / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
      return mid;

    int maxVal = arr[mid], peekIdx = 0;
    bool direction = true; // true 为向右边扫描，false 为左边
    if (arr[mid] < arr[mid - 1])
      direction = false;

    int i = mid, increment = direction ? 1 : -1;
    while (i < n && i >= 0)
    {
      if (arr[i] > maxVal)
      {
        maxVal = arr[i];
        peekIdx = i;
      }
      i += increment;
    }

    return peekIdx;
  }
};

int main(void)
{

  return 0;
}
