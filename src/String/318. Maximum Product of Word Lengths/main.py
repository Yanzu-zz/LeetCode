from itertools import combinations


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        # one-liner
        n, s, l = len(words), list(map(set, words)), list(map(len, words))
        return max((l[i] * l[j] for i, j in combinations(range(n), 2) if s[i] & s[j] == set()), default=0)
