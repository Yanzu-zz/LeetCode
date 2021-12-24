#include <iostream>
#include <vector>

using namespace std;

class Solution88
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    if (nums1.size() == 0)
    {
      nums1 = nums2;
      return;
    }
    else if (nums2.size() == 0)
      return;

    vector<int> tmp;
    int p1 = 0, p2 = 0;

    while (p1 < m || p2 < n)
    {
      if (p1 >= m)
        tmp.emplace_back(nums2[p2++]);
      else if (p2 >= n)
        tmp.emplace_back(nums1[p1++]);
      else
      {
        int a = nums1[p1];
        int b = nums2[p2];
        if (a <= b)
        {
          tmp.emplace_back(a);
          p1++;
        }
        else
        {
          tmp.emplace_back(b);
          p2++;
        }
      }
    }

    nums1 = tmp;
  }
};

int main(void)
{

  return 0;
}
