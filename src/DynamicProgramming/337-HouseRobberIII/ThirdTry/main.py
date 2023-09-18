# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root is None:
                return 0, 0

            l_rob, l_not_rot = dfs(root.left)
            r_rob, r_not_rot = dfs(root.right)
            rob = root.val + l_not_rot + r_not_rot
            not_rob = max(l_rob, l_not_rot) + max(r_rob, r_not_rot)
            return rob, not_rob

        return max(dfs(root))
