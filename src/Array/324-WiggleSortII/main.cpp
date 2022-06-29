#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    vector<int> tmp = nums;
    int n = tmp.size();
    sort(tmp.begin(), tmp.end());

    int l = n - 1 >> 1, r = n - 1;
    for (int i = 0; i < n; i++)
    {
      if (i & 1)
        nums[i] = tmp[r--];
      else
        nums[i] = tmp[l--];
    }
  }
};

int main(void)
{

  return 0;
}
