class Solution:
    def longestDecomposition(self, text: str) -> int:
        res = 0

        while text:
            i = 1
            lenS = len(text) // 2
            # 先找到分割点
            while i <= lenS and text[:i] != text[-i:]:
                i += 1

            # 无法分割情况
            if i > lenS:
                res += 1
                break

            # 能分割
            res += 2
            text = text[i:-i]
        return res
