from collections import deque
from queue import Queue
from typing import List


class LockingTree:

    def __init__(self, parent: List[int]):
        self.n = len(parent)
        # isLocked[i] = j：查询 节点i 是否被某个用户j锁定，如没有，j = -1
        self.isLocked = [-1] * len(parent)

    def lock(self, num: int, user: int) -> bool:
        if self.isLocked[num] != -1:
            return False

        self.isLocked[num] = user
        return True

    def unlock(self, num: int, user: int) -> bool:
        if self.isLocked[num] == -1:
            return False
        if self.isLocked[num] != user:
            return False

        self.isLocked[num] = -1
        return True

    def upgrade(self, num: int, user: int) -> bool:
        # only can upgrade node when 3 conditions below are all satisfied
        # The node is unlocked
        if self.isLocked[num] != -1:
            return False

        # It has at least one locked descendant (by any user), and
        de = self.checkDescendant(num)
        # It does not have any locked ancestors.
        an = self.checkAncestor(num)

        if de and an:
            self.isLocked[num] = user
            return True
        return False

    def checkDescendant(self, num):
        q = deque()
        q.append(num)
        flag = False

        # check descendant lock(at least one)
        while len(q) > 0:
            # 查询当前节点是否 locked 了
            curV = q.popleft()

            # 只要有一个子节点是 locked 状态，则可以进行 upgrade 操作
            if self.isLocked[curV] != -1:
                flag = True
                self.isLocked[curV] = -1

            # 当前节点的左节点
            tmp = (curV << 1) + 1
            if tmp < self.n:
                q.append(tmp)
            if tmp + 1 < self.n:
                q.append(tmp + 1)

        return flag

    def checkAncestor(self, num):
        q = deque()
        q.append(num)

        # check descendant lock(at least one)
        while len(q) > 0:
            # 查询当前节点是否 locked 了
            curV = q.popleft()

            # 只要有个父辈节点 locked 了就不能进行 upgrade 操作
            if self.isLocked[curV] != -1:
                return False

            # 当前节点的父亲节点
            tmp = ((curV + 1) >> 1) // 2
            if tmp > 0:
                q.append(tmp)

        return self.isLocked[0] == -1
