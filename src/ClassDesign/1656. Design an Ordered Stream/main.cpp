#include <iostream>
#include <vector>

using namespace std;

class OrderedStream
{
public:
  int N, currWantedIdx = 1;
  vector<string> record;
  OrderedStream(int n)
  {
    N = n + 1;
    record.resize(n + 1);
  }

  vector<string> insert(int idKey, string value)
  {
    vector<string> res;
    record[idKey] = value;
    // 如果检测到了期望的索引
    if (idKey == currWantedIdx)
    {
      // 则一直连续输出
      while (currWantedIdx <= N && record[currWantedIdx] != "")
        res.emplace_back(record[currWantedIdx++]);
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
