#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string customSortString(string order, string s)
  {
    vector<int> val(26);
    int n = order.size();
    // 对出现的字母顺序赋予优先级
    for (int i = 0; i < n; i++)
      val[order[i] - 'a'] = i + 1;

    sort(s.begin(), s.end(), [&](char c1, char c2)
         { return val[c1 - 'a'] < val[c2 - 'a']; });

    return s;
  }
};

int main(void)
{

  return 0;
}
