#include <iostream>
#include <vector>

using namespace std;

class Solution806
{
public:
  vector<int> numberOfLines(vector<int> &widths, string s)
  {
    int n = s.size();
    int lines = 1, weight = 0;

    for (int i = 0; i < n; i++)
    {
      int tmp = weight + widths[s[i] - 'a'];
      // 如果当前权重超过100了，则要到下一行写
      if (tmp > 100)
      {
        weight = widths[s[i] - 'a'];
        lines++;
      }
      else
      {
        // 否则就正常的加上上权值
        weight = tmp;
      }
    }

    return {lines, weight};
  }
};

int main(void)
{

  return 0;
}
