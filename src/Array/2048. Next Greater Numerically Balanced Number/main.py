from collections import Counter


class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        for x in range(n + 1, 1224445):
            count = Counter(str(x))

            if all(count[d] == int(d) for d in count):
                return x
