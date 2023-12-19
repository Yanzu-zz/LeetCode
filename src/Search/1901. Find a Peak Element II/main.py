from typing import List


class Solution:
    def isPeak(self, mat, i, j):
        m, n = len(mat), len(mat[0])
        # 和上面值比较谁大
        if i > 0 and mat[i][j] < mat[i - 1][j]:
            return [-1, 0]
        # 左边
        if j > 0 and mat[i][j] < mat[i][j - 1]:
            return [0, -1]
        # 下边
        if i < m - 1 and mat[i][j] < mat[i + 1][j]:
            return [1, 0]
        # 右边
        if j < n - 1 and mat[i][j] < mat[i][j + 1]:
            return [0, 1]

        # 不用动就是 peak
        return [0, 0]

    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        m, n = len(mat), len(mat[0])

        l, r = 0, n - 1
        while l < r:
            mid = l + (r - l) // 2
            if mat[0][mid] > mat[0][mid + 1]:
                r = mid
            else:
                l = mid + 1

        # 重合的时候就是找到当前行的峰值点了
        i = 0
        while i < m:
            x, y = self.isPeak(mat, i, l)
            if x == 0 and y == 0:
                break
            i += x
            l += y

        return [i, l]


arr = [[25, 37, 23, 37, 19], [45, 19, 2, 43, 26], [18, 1, 37, 44, 50]]
print(Solution().findPeakGrid(arr))
