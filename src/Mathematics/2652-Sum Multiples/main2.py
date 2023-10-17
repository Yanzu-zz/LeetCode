class Solution:
    def sumOfMultiples(self, n: int) -> int:
        def s(m):
            k = n // m
            return k * (k + 1) // 2 * m

        # 容斥原理
        return s(3) + s(5) + s(7) - s(15) - s(21) - s(35) + s(105)
