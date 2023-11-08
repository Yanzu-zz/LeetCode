class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = 0
        n = len(s)
        i = s.find("0")

        while i < n:
            vote0, vote1 = 0, 0
            while i < n and s[i] == '0':
                vote0 += 1
                i += 1
            while i < n and s[i] == '1':
                vote1 += 1
                i += 1

            ans = max(ans, min(vote0, vote1) << 1)

        return ans
