from heapq import heapify, heapreplace


class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        # 变成负号建最小堆，此时加负号就是最大堆
        nums = [-num for num in nums]
        heapify(nums)

        ans = 0
        for _ in range(k):
            # 注意，此时 nums[i] 为负数，故 // 会向下取整也就是变成更大（abs)
            ans -= heapreplace(nums, nums[0] // 3)

        return ans
