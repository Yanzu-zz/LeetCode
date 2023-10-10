class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        n = len(nums)
        pos = sorted([(nums[i] - d if s[i] == 'L' else nums[i] + d) for i in range(n)])
        # 数学化简一下有 i 个 ai，（n-i）个 ai-1
        dis = [(pos[i] * i) - (pos[i - 1] * (n - i)) for i in range(1, n)]
        return sum(dis) % (10 ** 9 + 7)
