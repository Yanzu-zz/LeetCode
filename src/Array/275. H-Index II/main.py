class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        ans = 0

        for i in range(n - 1, -1, -1):
            if citations[i] <= ans:
                break
            ans += 1
            
        return ans
