#include <iostream>
#include <vector>

using namespace std;

class Solution_Sword69
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int n = arr.size(), peekIdx = 0;
    if (arr[0] > arr[1])
      return 0;
    else if (arr[n - 1] > arr[n - 2])
      return n - 1;

    int left = 0, right = n - 1;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) // 找到山峰了
      {
        right = mid;
        break;
      }
      else if (arr[mid] < arr[mid - 1]) // 山峰在左边
      {
        right = mid;
      }
      else if (arr[mid] < arr[mid + 1]) // 山峰在右边
      {
        left = mid + 1;
      }
    }

    return right;
  }
};

int main(void)
{

  return 0;
}
