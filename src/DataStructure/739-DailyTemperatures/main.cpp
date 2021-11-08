#include <iostream>
#include <vector>

using namespace std;

class Solution739
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    vector<int> res(n, 0);

    // 暴力，具体看代码就好
    for (int i = 0; i < n; i++)
    {
      int j;
      for (j = i + 1; j < n && temperatures[i] > temperatures[j]; j++) ;

      if (j < n)
        res[i] = j - i;
    }

    return res;
  }
};

int main()
{

  return 0;
}