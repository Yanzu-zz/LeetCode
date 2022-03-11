#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution2049
{
private:
  int n, res;
  long maxScore;

  // 计算三个节点群数量的辅助函数
  long mult3(long a, long b, long c)
  {
    a = a == 0 ? 1 : a;
    b = b == 0 ? 1 : b;
    c = c == 0 ? 1 : c;

    return a * b * c;
  }

  int dfs(int currNode, vector<int> &left, vector<int> &right)
  {
    if (currNode == -1)
      return 0;

    // 左右子节点的数量
    int leftCnt = dfs(left[currNode], left, right);
    int rightCnt = dfs(right[currNode], left, right);
    // 父节点的数量，知道了左右节点以及全部节点的数量就能求
    int remain = n - leftCnt - rightCnt - 1;

    // 接着就是计算了，如果计算结果大于目前记录的最大得分的话就抹平重来
    // 要用 long 防止越界
    long score = mult3(leftCnt, rightCnt, remain);
    if (score > maxScore)
    {
      maxScore = score;
      res = 1;
    }
    else if (score == maxScore)
    {
      res++;
    }

    // 这题不需要记忆化搜索，因为深搜的过程中会顺带计算每个节点的分数，没有重复递归的操作
    return leftCnt + rightCnt + 1;
  }

public:
  int countHighestScoreNodes(vector<int> &parents)
  {
    n = parents.size();

    vector<int> left(n, -1), right(n, -1);
    // 构建二叉树
    for (int i = 1; i < n; i++)
    {
      int p = parents[i];
      if (left[p] == -1)
        left[p] = i;
      else
        right[p] = i;
    }

    // 然后就是深搜找答案了
    dfs(0, left, right);

    return res;
  }
};

int main(void)
{

  return 0;
}
