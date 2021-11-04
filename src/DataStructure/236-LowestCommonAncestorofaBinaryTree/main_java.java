public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution236 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 这里是精髓，定位待判断的结点，当然一开始的边界条件判断也是必须滴
        if (root == null || root == p || root == q)
            return root;

        // 接下来就查询左右子树
        // 因为是递归，使用函数后可认为左右子树已经算出结果
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        // 若左子树查询结果为 null，则表明两个节点都在右子树，那么我们返回右子树查询到的节点即可
        if (left == null)
            return right;
        else if (right == null) // 同理
            return left;
        else // 两科子树都查询到结果，那么说明当前结点就是最近公共子结点
            return root;
    }
}