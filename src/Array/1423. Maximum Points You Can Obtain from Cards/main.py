class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        s = ans = sum(cardPoints[:k])

        # 减去 k-i，并且加上逐次后面的元素，查看哪个和最大
        for i in range(1, k + 1):
            s += cardPoints[-i] - cardPoints[k - i]
            ans = max(ans, s)

        return ans
