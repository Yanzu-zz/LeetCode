from cmath import inf
from collections import deque


class StockSpanner:

    def __init__(self):
        self.q = []

    def next(self, price: int) -> int:
        cnt, a, b = 1, 0, 0
        # 单调栈，如果当前的 price 比之前的大，则一个一个计算 cnt 数量
        while len(self.q) > 0 and a < price:
            a, b = self.q[-1]
            if a <= price:
                cnt += b
                self.q.pop()
        self.q.append((price, cnt))
        return cnt


# Your StockSpanner object will be instantiated and called as such:
obj = StockSpanner()
print(obj.next(100))
print(obj.next(80))
print(obj.next(60))
print(obj.next(70))
print(obj.next(60))
print(obj.next(75))
print(obj.next(85))
