class Solution:
    def maxProduct(self, words: List[str]) -> int:
        ans = 0
        mask = [0] * len(words)
        for i, word in enumerate(words):
            # 获取当前 word 的所有字母
            # 一个字母出现一次和出现无数次都等价
            for c in word:
                mask[i] |= 1 << ord(c) - ord("a")

            # 接着就是暴力遍历前面出现过的 word 与当前 word 做对比
            for j in range(0, i):
                if mask[i] & mask[j] == 0:
                    ans = max(ans, len(words[i]) * len(words[j]))

        return ans
