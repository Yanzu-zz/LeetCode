class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        n = len(player1)

        # 单独计算某个玩家的分数
        def calcScore(p):
            res = 0
            # isDouble 做双倍占位符
            isDouble = 0
            for i in range(n):
                res += (2 if isDouble > 0 else 1) * p[i]
                isDouble -= 1
                if p[i] == 10:
                    isDouble = 2
            return res

        aScore, bScore = calcScore(player1), calcScore(player2)
        if aScore == bScore:
            return 0
        return 1 if aScore > bScore else 0
