#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
  vector<int> minOperations(string boxes)
  {
    int n = boxes.size();
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
      // 遇到的是 0跳过不用理
      if (boxes[i] == '0')
        continue;

      // 遇到是 1 就遍历计算每个位置的次数
      for (int j = 0; j < n; j++)
        res[j] += abs(i - j);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
