#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution575
{
public:
  int distributeCandies(vector<int> &candyType)
  {
    int n = candyType.size();
    sort(candyType.begin(), candyType.end());

    // 排序后判断是否是新的元素，是的话最终能分到的糖果数量++
    int count = 1; // 初始化为1（candyType[0]肯定是一个）
    for (int i = 1; i < n && count < n / 2; i++)
      if (candyType[i] != candyType[i - 1])
        count++;

    return count;
  }
};

int main()
{

  return 0;
}