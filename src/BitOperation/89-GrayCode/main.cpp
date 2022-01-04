#include <iostream>
#include <vector>

using namespace std;

class Solution89
{
public:
  vector<int> grayCode(int n)
  {
    vector<int> res;
    res.emplace_back(0);

    int head = 1;
    // 根据解题思路来
    for (int i = 0; i < n; i++)
    {
      for (int j = res.size() - 1; j >= 0; j--)
        res.emplace_back(head + res[j]);
      head <<= 1;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
