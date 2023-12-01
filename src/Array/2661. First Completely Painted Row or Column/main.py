class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        n, m = len(mat), len(mat[0])
        aLen = m * n

        # 标注在 mat 中的下标
        mp = {mat[i][j]: [i, j] for i in range(n) for j in range(m)}

        rowCnt, colCnt = [0] * n, [0] * m
        # 按照 arr 的元素顺序涂抹 mat矩阵
        for i in range(aLen):
            cur = mp[arr[i]]

            # 只要一行或者一列都涂满了，就返回当前索引
            rowCnt[cur[0]] += 1
            if rowCnt[cur[0]] == m:
                return i

            colCnt[cur[1]] += 1
            if colCnt[cur[1]] == n:
                return i

        return -1
