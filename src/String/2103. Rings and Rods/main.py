class Solution:
    def countPoints(self, rings: str) -> int:
        R = [0] * 10
        G = [0] * 10
        B = [0] * 10

        for i in range(1, len(rings), 2):
            cur = int(rings[i])
            if rings[i - 1] == 'R':
                R[cur] += 1
            elif rings[i - 1] == 'G':
                G[cur] += 1
            else:
                B[cur] += 1

        return sum([1 for i in range(10) if R[i] >= 1 and G[i] >= 1 and B[i] >= 1])
