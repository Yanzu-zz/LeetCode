#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution575
{
public:
  int distributeCandies(vector<int> &candyType)
  {
    // 设糖果数量为n，由于妹妹只能分到一半的糖果，所以答案不会超过 n/2；另一方面，设这些糖果一共有 m 种，答案也不会超过m/2
    // 而很明显我们题目的逻辑是求这两个数字较小的那个
    return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
  }
};

int main()
{

  return 0;
}