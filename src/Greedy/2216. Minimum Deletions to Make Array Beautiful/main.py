class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        cnt = 0
        n = len(nums)

        # 遇到不符合题目情况的直接贪心删除就行
        for i in range(n - 1):
            idx = i - cnt
            # 用 idx 来模拟当前真正的元素索引
            if idx % 2 == 0 and nums[i] == nums[i + 1]:
                cnt += 1

        return cnt + 1 if (n - cnt) % 2 == 1 else cnt
