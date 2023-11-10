class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        n = len(s)
        i = 0
        l, r = 0, 0
        ans = 0

        while i < n:
            vote = 0
            l, r = i, i
            while r < n and s[r] == '0':
                vote += 1
                r += 1
            while r < n and s[r] == '1' and vote > 0:
                vote -= 1
                r += 1

            i = r + 1
            ans = max(ans, r - l)

        return ans
