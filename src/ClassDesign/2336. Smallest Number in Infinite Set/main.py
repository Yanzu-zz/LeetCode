from sortedcontainers import SortedSet


class SmallestInfiniteSet:

    # 可以自己实现一个头插法链表实现
    def __init__(self):
        # self.s = set(range(1, 1001))
        self.s = SortedSet(range(1, 1001))

    def popSmallest(self) -> int:
        # 需要判断是否为空
        x = -1
        if len(self.s) > 0:
            x = self.s[0]
            self.s.remove(x)
        return x

    def addBack(self, num: int) -> None:
        self.s.add(num)

# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
