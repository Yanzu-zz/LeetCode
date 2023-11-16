class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        n = len(nums)
        ans = 0
        i = 0
        while i < n:
            if nums[i] > threshold or nums[i] % 2 != 0:
                i += 1
                continue

            isEO = 1
            j = i + 1
            while j < n and nums[j] <= threshold and nums[j] % 2 == isEO:
                j += 1
                isEO = (isEO + 1) % 2
            ans = max(ans, j - i)
            i = j

        return ans
