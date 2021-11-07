#include <iostream>
#include <vector>

using namespace std;

class Solution621
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    int len = tasks.size();
    vector<int> tasksOccur(26, 0); // 每个“task”需要调度的次数
    for (const char &task : tasks)
      tasksOccur[task - 'A']++;
      
    // 对待调度的命令次数进行排序
    sort(tasksOccur.rbegin(), tasksOccur.rend()); // 将任务从大到小排序，好弄清楚最耗时的任务是哪个

    // 如果最耗时的任务有 cnt 个，则最后一轮调度次数就是单纯的加法
    int cnt = 1;
    while (cnt < tasksOccur.size() && tasksOccur[cnt] == tasksOccur[0])
      cnt++;

    // 按照笔记里面的公式计算
    return max(len, (tasksOccur[0] - 1) * (n + 1) + cnt);
  }
};

int main()
{

  return 0;
}