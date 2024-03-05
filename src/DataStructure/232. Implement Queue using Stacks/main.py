class MyQueue:
    def __init__(self):
        # s1 为入队栈，s2 为出队栈
        self.s1 = []
        self.s2 = []

    def push(self, x: int) -> None:
        self.s1.append(x)

    def pop(self) -> int:
        if len(self.s2) <= 0:
            for i in range(len(self.s1)):
                self.s2.append(self.s1.pop())

        return self.s2.pop()

    def peek(self) -> int:
        if len(self.s2) == 0:
            return self.s1[0]
        return self.s2[-1]

    def empty(self) -> bool:
        return (len(self.s1) + len(self.s2)) <= 0
