#include <iostream>
#include <vector>

using namespace std;

class Solution794
{
private:
  // 判断传入的 board 井字棋棋盘情况是否有赢（p 为身份）
  bool win(vector<string> &board, char p)
  {
    for (int i = 0; i < 3; i++)
    {
      // 查看当前行有无连续三个 p，有则胜利咯
      if (p == board[i][0] && p == board[i][1] && p == board[i][2])
        return true;
      // 同理，这里是查看列
      if (p == board[0][i] && p == board[1][i] && p == board[2][i])
        return true;
    }

    // 下面是查看两个对角线的情况
    if (p == board[0][0] && p == board[1][1] && p == board[2][2])
      return true;
    if (p == board[0][2] && p == board[1][1] && p == board[2][0])
      return true;

    return false;
  }

public:
  bool validTicTacToe(vector<string> &board)
  {
    int xCount = 0, oCount = 0;
    // 记录 'X' 和 'O' 在棋盘 board 上的个数
    for (string &row : board)
    {
      for (char c : row)
      {
        if (c == 'X')
          xCount++;
        else if (c == 'O')
          oCount++;
      }
    }

    // 分类讨论
    // 如果棋子数量不对等，则表示该棋盘无效
    // 前面先判断 oCount != xCount 是短路操作，为了能让代码继续执行下去，核心代码是后面的，因为后手下棋一定是 等于 或者 等于 xCount-1 的数量
    if (oCount != xCount && oCount != xCount - 1)
      return false;
    // 下面就是检测输了某个胜利但是违规了的情况
    if (win(board, 'X') && oCount != xCount - 1)
      return false;
    if (win(board, 'O') && oCount != xCount)
      return false;

    // 分类全部通过则表明当前棋盘合法且胜利了（有连续三个子）
    return true;
  }
};

int main(void)
{

  return 0;
}
