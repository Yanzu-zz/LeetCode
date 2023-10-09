class Solution:
    def splitNum(self, num: int) -> int:
        # 将数字从小到大排序
        cnt = "".join(sorted(str(num)))
        # 然后逐个加入
        a, b = int(cnt[::2]), int(cnt[1::2])
        return a + b
