#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution406
{
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
  {
    int n = people.size();
    vector<vector<int>> res;
    // 先对 people 数组进行排序：第一个元素降序，第二个元素升序
    sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
         {
           if (a[0] != b[0])
             return a[0] > b[0];

           return a[1] < b[1];
         });

    // 拍完序后就按照笔记要求插入
    for (const auto &folk : people)
    {
      if (res.size() <= folk[1])
        res.push_back(folk);
      else
        res.insert(res.begin() + folk[1], folk);
    }

    return res;
  }
};

int main()
{

  return 0;
}