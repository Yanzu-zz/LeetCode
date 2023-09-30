class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        # 按照 growTime 从大到小排序
        com = sorted(zip(plantTime, growTime), key=lambda x: -x[1])
        ans = 0
        curDays = 0

        # 然后就是从 growTime 大的开始种植
        # 种的时候查看当前种子的 plattime + growtime 是否最大
        for p, g in com:
            curDays += p
            ans = max(ans, curDays + g)

        return ans
