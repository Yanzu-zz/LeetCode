
class Solution:
  def countBattleships(self, board: List[List[str]]) -> int:
    m, n = len(board), len(board[0])
    ans = 0

    # 其实就是判断左边和上边有没有战舰，有的话就不是新的战舰的头部
    for i in range(m):
      for j in range(n):
        if board[i][j] == 'X' and (i == 0 or board[i-1][j]) != 'X' and (j == 0 or board[i][j-1] != 'X'):
          ans += 1

    return ans
