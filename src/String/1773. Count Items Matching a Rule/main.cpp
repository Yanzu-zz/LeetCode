#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
  {
    int idx = 0;
    if (ruleKey == "color")
      idx = 1;
    else if (ruleKey == "name")
      idx = 2;

    int res = 0, n = items.size();
    for (int i = 0; i < n; i++)
      if (items[i][idx] == ruleValue)
        res++;

    return res;
  }
};

int main(void)
{

  return 0;
}
