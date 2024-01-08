from collections import Counter


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for x1, y1 in points:
            cnt = Counter()
            for x2, y2 in points:
                d2 = (x1 - x2) ** 2 + (y1 - y2) ** 2
                # 用哈希表来判断有多少个距离相等的点
                # 乘与2是因为顺序变一下又是一个新的回旋镖
                ans += cnt[d2] * 2
                cnt[d2] += 1

        return ans
