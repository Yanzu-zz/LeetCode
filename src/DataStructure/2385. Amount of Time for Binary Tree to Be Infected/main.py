# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
    infectedStep = -1
    maxStep = -1

    def dfs(root, step):
      if root is None:
        nonlocal maxStep
        maxStep = max(maxStep, step - 1)
        return

      # 找到感染的那个点了，记录根节点到这里的距离
      if root.val == start:
        infectedStep = step

      dfs(root.left, step+1)
      dfs(root.right, step+1)

    if root.val == start:
      dfs(root, 0)
      return maxStep
    
    dfs(root.left, 0)
    # 感染点在左边
    if infectedStep > -1:
      
