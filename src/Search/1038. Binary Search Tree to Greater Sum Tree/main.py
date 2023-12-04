# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 题目意思就是用所有比当前节点值 大于等于 的值，替换当前的节点 val
    # 又由于是搜索二叉树，当前节点的右子树的元素值都是大于等于当前节点Val的
    # 故我们用用后序遍历，从最大的那个节点开始累加，逐个替换值
    def bstToGst(self, root: TreeNode) -> TreeNode:
        s = 0

        def dfs(root):
            if root is None:
                return

            # 先遍历右子树的后序遍历
            dfs(root.right)

            nonlocal s
            # 累加
            s += root.val
            # 当前节点值替换成到当前节点的累加值
            root.val = s

            # 接着最后再遍历左子树
            dfs(root.left)

        dfs(root)
        return root
