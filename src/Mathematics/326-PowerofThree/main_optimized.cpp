#include <iostream>
#include <vector>

using namespace std;

class Solution326_1
{
private:
  vector<int> pre = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};

public:
  bool isPowerOfThree(int n)
  {
    //return find(pre.begin(), pre.end(), n) != pre.end();
    int len = pre.size();
    for (int i = 0; i < len && pre[i] <= n; i++)
      if (pre[i] == n)
        return true;

    return false;
  }
};

int main(void)
{

  return 0;
}
