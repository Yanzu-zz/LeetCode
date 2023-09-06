# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        ans = None
        maxDepth = -1

        def dfs(root, curDepth):
            nonlocal ans, maxDepth
            if root is None:
                maxDepth = max(maxDepth, curDepth)
                return curDepth

            lMaxDepth = dfs(root.left, curDepth + 1)
            rMaxDepth = dfs(root.right, curDepth + 1)
            if (lMaxDepth == rMaxDepth == maxDepth):
                ans = root

            return max(lMaxDepth, rMaxDepth)

        dfs(root, 0)
        return ans
