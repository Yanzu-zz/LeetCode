#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution636
{
public:
  vector<int> exclusiveTime(int n, vector<string> &logs)
  {
    vector<int> res(n, 0);
    stack<pair<int, int>> st;

    for (auto log : logs)
    {
      char type[6];
      int idx, timestamp;
      sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);

      // start or end?
      if (type[0] == 's')
      {
        if (!st.empty())
        {
          // 将上一个程序运行的时间累加
          res[st.top().first] += timestamp - st.top().second;
          st.top().second = timestamp; // 更新下时间
        }
        st.emplace(idx, timestamp);
      }
      else
      {
        auto t = st.top();
        st.pop();
        res[t.first] += timestamp - t.second + 1;
        if (!st.empty())
          st.top().second = timestamp + 1;
      }
    }

    return res;
  }
};

int main(void)
{
  vector<string> str1 = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
  vector<int> a = Solution636().exclusiveTime(2, str1);

  return 0;
}
