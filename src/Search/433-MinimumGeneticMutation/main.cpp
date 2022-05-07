#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution433
{
public:
  int minMutation(string start, string end, vector<string> &bank)
  {
    char geneKeys[4] = {'A', 'C', 'G', 'T'};
    // 进行广搜的队列
    queue<string> qu;
    // 记录生成过的基因字符串以及 bank 数组里面的合法基因字符串哈希表（用来快速判断是否合法）
    unordered_set<string> visited, bankElm;

    // 记录
    for (string &s : bank)
      bankElm.emplace(s);

    // 两种特判形式
    if (bankElm.count(end) == 0)
      return -1;
    if (start == end)
      return 0;

    // 初始化队列变量然后开始广搜
    int step = 1;
    qu.emplace(start);
    visited.emplace(start);

    while (!qu.empty())
    {
      // 一次验证 上一轮循环中 新增的合法的基因字符串
      int len = qu.size();
      for (int i = 0; i < len; i++)
      {
        // 取出一个字符串
        string curr = qu.front();
        qu.pop();
        // 一个基因字符串是由 8 个基因位组成的，所以我们这里要更改每个位置的字符
        for (int j = 0; j < 8; j++)
        {
          // 一个基因只有 4 个字符
          for (int k = 0; k < 4; k++)
          {
            // 只要当前需要改变位的基因字符不相等，就改变它（相等还判断的话也不会错，但会增加复杂度，所以这里相当于剪枝）
            if (curr[j] != geneKeys[k])
            {
              string next = curr;
              next[j] = geneKeys[k];

              // 接下来就是查看是否为合法字符串 并且 是否曾经加入过 qu 队列，是的话就不要重复加了，这样会导致死循环
              if (!visited.count(next) && bankElm.count(next))
              {
                if (next == end)
                  return step;

                // 如果没成功就记录该字符串，以及加入队列（可能这个 next 再改一个字符就能变为 end
                // 注意，必须是要 合法 才能执行下面两个操作
                visited.insert(next);
                qu.emplace(next);
              }
            }
          }
        }
      }

      // 一次只能更改一个字符，故我们 +1
      // 它这里，一次循环的 队列元素，就是上一次基因字符串 变化一次得来的，故我们每轮实际上就是多了一次 step
      step++;
    }

    return -1;
  }
};

int main(void)
{

  return 0;
}
