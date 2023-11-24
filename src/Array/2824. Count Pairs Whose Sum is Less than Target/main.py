class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        # 排序 + 二分
        nums.sort()
        ans, n = 0, len(nums)

        for i in range(1, n):
            l, r = 0, i - 1
            while l < r:
                mid = l + r + 1 >> 1
                # 此时发现两者相加大于 target，r 要变小
                if nums[i] + nums[mid] < target:
                    l = mid
                else:
                    r = mid - 1
            if nums[i] + nums[r] < target:
                ans += r + 1

        return ans
