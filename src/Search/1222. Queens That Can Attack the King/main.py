class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        n = 8
        direction = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
        s = set(map(tuple,queens))
        ret = []

        # 也就是朝每个方向走一遍，遇到的第一个queen就加入ret数组，其余抛弃
        for a, b in direction:
            x = king[0] + a
            y = king[1] + b
            while 0 <= x < n and 0 <= y < n:
                if (x, y) in s:
                    ret.append([x, y])
                    break
                x += a
                y += b

        return ret
