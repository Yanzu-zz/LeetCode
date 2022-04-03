#include <iostream>
#include <vector>

using namespace std;

class Solution744
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int n = letters.size();
    if (letters[n - 1] <= target)
      return letters[0];

    // 暴力查找
    int i = 0;
    for (; i < n && letters[i] <= target; i++)
      ;

    return letters[i];
  }
};

int main(void)
{

  return 0;
}
