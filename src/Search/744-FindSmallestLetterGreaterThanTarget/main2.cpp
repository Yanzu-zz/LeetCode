#include <iostream>
#include <vector>

using namespace std;

class Solution744
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int left = 0, right = letters.size() - 1;
    // 直接看看最大的元素是否比 target 大，不大的话则循环回开头
    if (letters[right] <= target)
      return letters[0];

    // 二分查找
    while (left != right)
    {
      int mid = left + (right - left >> 1);
      if (letters[mid] <= target)
        left = mid + 1;
      else
        right = mid;
    }

    return letters[left];
  }
};

int main(void)
{

  return 0;
}
