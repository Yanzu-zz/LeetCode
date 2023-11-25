# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:
        cnt = [0] * 10

        def dfs(root):
            # 到底了
            if root is None:
                return 0
            cnt[root.val] ^= 1

            # 是叶子节点
            if root.left is root.right:
                res = 1 if sum(cnt) <= 1 else 0
            else:
                # 记录 root.val 出现的次数（这里只会在 0和1 之间变换，表示出现的奇偶次数）
                res = dfs(root.left) + dfs(root.right)
            cnt[root.val] ^= 1
            return res

        return dfs(root)
