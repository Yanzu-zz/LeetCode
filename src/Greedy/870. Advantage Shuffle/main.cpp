#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    // 对nums1排序，以便每次选取第一个比 nums2[i]大的元素
    sort(nums1.begin(), nums1.end());

    vector<int> res(n);
    vector<bool> visited(n, false);

    int curr = 0;
    for (int i = 0; i < n; i++)
    {
      bool flag = false;
      for (int j = 0; j < n; j++)
      {
        if (!visited[j] && nums1[j] > nums2[curr])
        {
          res[curr] = nums1[j];
          visited[j] = true;
          curr++;
          flag = true;
          break;
        }
      }

      // 如果没执行到
      if (!flag)
      {
        int i = 0;
        for (; visited[i]; i++)
          ;
        res[curr++] = nums1[i];
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
