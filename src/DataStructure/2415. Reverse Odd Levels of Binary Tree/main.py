# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from itertools import chain


class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = [root]
        # 判断是否奇数层
        isOdd = 1

        # BFS
        while q[0].left:
            # 这里就是 BFS 里的加节点
            q = list(chain.from_iterable((node.left, node.right) for node in q))
            if isOdd == 1:
                l, r = 0, len(q) - 1
                while l < r:
                    q[l].val, q[r].val = q[r].val, q[l].val
                    l += 1
                    r -= 1
            isOdd ^= 1

        return root
