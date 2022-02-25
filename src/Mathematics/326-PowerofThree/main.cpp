#include <iostream>
#include <vector>

using namespace std;

class Solution326
{
private:
  vector<long> pre;

public:
  bool isPowerOfThree(int n)
  {
    long tmp = 1;
    pre.push_back(tmp);
    while (tmp * 3 <= n)
    {
      tmp *= 3;
      pre.push_back(tmp);
    }
    return find(pre.begin(), pre.end(), n) != pre.end();
  }
};

int main(void)
{

  return 0;
}
