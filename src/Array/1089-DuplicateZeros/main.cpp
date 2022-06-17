#include <iostream>
#include <vector>

using namespace std;

class Solution1089
{
public:
  void duplicateZeros(vector<int> &arr)
  {
    int n = arr.size();
    int i = 0, j = n - 1, k = n - 1;

    // 先确定有多少个 0，需要往后挪几个位置
    for (int i = 0; i < n && i <= j; i++)
    {
      if (arr[i] == 0)
      {
        if (i == j)
        {
          arr[k--] = 0;
          j--;
          break;
        }
        j--;
      }
    }

    if (j != n - 1)
    {
      // 然后就是变成题目想要的格式
      while (j >= 0)
      {
        if (arr[j] == 0)
          arr[k--] = 0;
        arr[k--] = arr[j--];
      }
    }
  }
};

int main()
{

  return 0;
}