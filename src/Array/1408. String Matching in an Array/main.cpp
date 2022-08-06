#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution1408
{
public:
  vector<string> stringMatching(vector<string> &words)
  {
    // 按长度排序
    sort(words.begin(), words.end(), [](const string a, const string b)
         { return a.size() < b.size(); });

    int n = words.size();
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        // 查看是否为子字符串
        const char *idx = strstr(words[j].c_str(), words[i].c_str());
        if (idx)
        {
          res.emplace_back(words[i]);
          break;
        }
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
