class Solution:
    def giveGem(self, gem: List[int], operations: List[List[int]]) -> int:
        for a, b in operations:
            tmp = gem[a] // 2
            gem[b] += tmp
            gem[a] -= tmp

        maxV, minV = gem[0],gem[0]
        for v in gem:
            maxV = max(maxV, v)
            minV = min(minV, v)

        return maxV - minV
