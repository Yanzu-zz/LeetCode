#include <iostream>
#include <vector>

using namespace std;

class Solution1791
{
public:
  int findCenter(vector<vector<int>> &edges)
  {
    int a = edges[0][0], b = edges[0][1];

    return (a == edges[1][0] || a == edges[1][1]) ? a : b;
  }
};

int main(void)
{

  return 0;
}
