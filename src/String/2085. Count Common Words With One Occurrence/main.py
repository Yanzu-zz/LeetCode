from collections import Counter


class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        cnt1 = Counter(words1)
        cnt2 = Counter(words2)
        # 两个数组里面都只出现了一次
        return sum(v == 1 and cnt2[w] == 1 for w, v in cnt1.items())
