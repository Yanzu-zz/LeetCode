#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution630
{
public:
  int scheduleCourse(vector<vector<int>> &courses)
  {
    // 按课程截止时间升序排序
    sort(courses.begin(), courses.end(), [](const auto &a, const auto &b)
         { return a[1] < b[1]; });
    // 大根堆，学习时长更长的在堆顶
    priority_queue<int> q;
    // 记录总学习时长
    int total = 0;

    // 按截止时间从近到远遍历课程
    for (const auto &course : courses)
    {
      int ti = course[0], di = course[1];
      // 如果总时长不会超过截止时间，那么，当前这门课程可以选择，直接入堆
      if (total + ti <= di)
      {
        total += ti;
        q.push(ti);
      }
      else if (!q.empty() && q.top() > ti)
      {
        // 出现冲突，优先选择学习时长更短的课程
        total -= q.top() - ti;
        q.pop();
        q.push(ti);
      }
    }
    
    // 堆中有多少课程就是结果
    return q.size();
  }
};

int main(void)
{

  return 0;
}
