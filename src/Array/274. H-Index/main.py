class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)

        n = len(citations)
        ans = 0
        for citation in citations:
            # 到了第 i 个若比 i 小，则 h 指数为当前的
            if citation <= ans:
                break
            ans += 1

        return ans
