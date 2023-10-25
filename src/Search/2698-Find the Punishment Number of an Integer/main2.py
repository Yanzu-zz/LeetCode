class Solution:
    def punishmentNumber(self, n):
        numbers = [1, 9, 10, 36, 45, 55, 82, 91, 99, 100, 235, 297, 369, 370, 379, 414, 657, 675, 703, 756, 792, 909,
                   918, 945, 964, 990, 991, 999, 1000]
        return sum([a ** 2 for a in numbers if a <= n])
        # i, ans = 0, 0
        # while i < len(numbers) and numbers[i] <= n:
        #     ans += numbers[i] ** 2
        #     i += 1
        #
        # return ans
