class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        arr = [0] * 1001

        # 差分数组
        for num, from_, to_ in trips:
            arr[from_] += num
            arr[to_] -= num

        # 接下来就是累加起来查看是否有超过 capacity 的情况
        # return max(s for s in accumulate(arr)) <= capacity
        return all(s <= capacity for s in accumulate(arr))
