class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        # main1 one-liner 写法
        curDays, ans = 0, 0

        for p, g in sorted(zip(plantTime, growTime), key=lambda x: -x[1]):
            curDays += p
            ans = max(ans, curDays + g)

        return ans
