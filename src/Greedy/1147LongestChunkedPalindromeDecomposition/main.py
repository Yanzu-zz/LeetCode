class Solution:
    def longestDecomposition(self, text: str) -> int:
        if text == "":
            return 0

        lenS = (len(text) >> 1) + 1
        for i in range(0, lenS):
            # 找到分割点
            if text[:i] == text[-i:]:
                # 然后继续寻找
                return 2 + self.longestDecomposition(text[i:-i])

        return 1
