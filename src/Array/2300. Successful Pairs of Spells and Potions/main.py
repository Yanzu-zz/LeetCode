class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        return [len(potions) - bisect_left(potions, success / x) for x in spells]
        # n = len(potions)
        # ans = [0] * len(spells)
        #
        #
        # for i, spell in enumerate(spells):
        #     l, r = 0, n - 1
        #     while l <= r:
        #         mid = l + (r - l) // 2
        #         if spell * potions[mid] >= success:
        #             r = mid - 1
        #         else:
        #             l = mid + 1
        #
        #     ans[i] = n - r - 1
        #
        # return ans
