class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        # 不从 [0][0] 位置开始直接判负
        if (grid[0][0] != 0):
            return False

        # 八个方向的逆时针增量（只能走日字）
        direction = [[1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1], [-2, 1], [-1, 2]]

        # 接着就开始暴力模拟
        n = len(grid)
        gLen = n * n
        x, y = 0, 0
        # 这里不需要哈希表记录走过情况，只需要确保八个方向上能走到下个 val
        for target in range(1, gLen):
            # 搜索下个target val
            for a, b in direction:
                nextY = y + a
                nextX = x + b
                if nextX >= 0 and nextX < n and nextY >= 0 and nextY < n and grid[nextY][nextX] == target:
                    x = nextX
                    y = nextY
                    break
            # 八个方向都没找到下个 target 数值，直接返回 False
            else: return False

        # 反正只要没判负也就是能走通
        return True
