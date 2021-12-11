#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TopVotedCandidate
{
private:
  int leading[5001]; // 在某个时间点得票数领先的人
  vector<int> times;

public:
  // 初始化时记录每个索引位的 领先选举人
  TopVotedCandidate(vector<int> &persons, vector<int> &times)
  {
    int n = persons.size();

    unordered_map<int, int> electors;
    int topName = -1; // 当前领先的选举人的名字（是个数字，存在 persons 里面）
    electors[-1] = -1;

    for (int i = 0; i < n; i++)
    {
      int person = persons[i];
      electors[person]++; // 给 person 加上一票

      // 更换当前时间点领先选举人
      // 因为题目要求若平局（即票数相等），则领先人物要为这轮被投的人，即 person
      if (electors[person] >= electors[topName])
        topName = person;

      // 无论当前领先的人有无变化，这轮次的领先人物都要加进数组中
      this->leading[i] = topName;
    }

    this->times = times; // 要记录下这个 times 数组给 q() 查询用
  }

  // 用二分查找查询 离 最近 的时刻的领先人物
  // 此处用 upper_bound 查询即可，具体实现可自己后面细究
  int q(int t)
  {
    // upper_bound - times.betin() 得到最近的元素时第几个位置 （从 1 开始）
    // 接着 - 1 是为了匹配数组从 0 开始的问题
    int nearestIdx = (upper_bound(times.begin(), times.end(), t) - times.begin()) - 1;
    return *(leading + nearestIdx);
  }
};

int main(void)
{

  return 0;
}
