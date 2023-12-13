class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        cur = list(s)
        l, r = 0, len(cur) - 1

        while l < r:
            t = cur[l] if cur[l] < cur[r] else cur[r]
            cur[l] = t
            cur[r] = t
            l += 1
            r -= 1

        return ''.join(cur)
