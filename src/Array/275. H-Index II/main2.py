class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        l, r = 0, n - 1

        # 二分查找
        while l <= r:
            # mid = l + (r - l // 2)
            mid = (l + r) // 2
            if citations[mid] >= n - mid:
                r = mid - 1
            else:
                l = mid + 1

        return n - l
