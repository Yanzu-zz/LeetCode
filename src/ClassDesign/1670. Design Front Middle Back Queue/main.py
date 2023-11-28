class FrontMiddleBackQueue:

    def __init__(self):
        self.arr = []

    def pushFront(self, val: int) -> None:
        self.arr.insert(0, val)

    def pushMiddle(self, val: int) -> None:
        idx = len(self.arr) // 2
        self.arr.insert(idx, val)

    def pushBack(self, val: int) -> None:
        self.arr.append(val)

    def popFront(self) -> int:
        if len(self.arr) > 0:
            return self.arr.pop(0)
        else:
            return -1

    def popMiddle(self) -> int:
        if len(self.arr) > 0:
            idx = (len(self.arr) - 1) // 2
            return self.arr.pop(idx)
        else:
            return -1

    def popBack(self) -> int:
        if len(self.arr) > 0:
            return self.arr.pop()
        else:
            return -1

# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()
