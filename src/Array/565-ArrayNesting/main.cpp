#include <iostream>
#include <vector>

using namespace std;

class Solution565
{
public:
  int arrayNesting(vector<int> &nums)
  {
    int n = nums.size(), res = 0;
    ;
    vector<bool> vis(n, false);

    // 建图
    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      // 遍历图，直到遇见环
      // 而只要是在最长长度的数组中，就一定会遍历完该环的全部长度
      // 后面遇到该环的成员就可以不理，剪枝
      // 只有不同环内的元素才会新便利到
      while (!vis[i])
      {
        vis[i] = true;
        i = nums[i];
        cnt++;
      }

      res = cnt > res ? cnt : res;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
