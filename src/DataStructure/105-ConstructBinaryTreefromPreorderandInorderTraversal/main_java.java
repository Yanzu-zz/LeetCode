import java.util.Arrays;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution105 {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length, m = inorder.length; // 题目保证他们两相同，但为了我们好区分，还是用了两个变量
        if (n == 0 || m == 0)
            return null;

        TreeNode root = new TreeNode(preorder[0]); // 构造根结点（前序第一个元素一定是当前数的根结点）
        for (int i = 0; i < m; i++) {
            // 找到中序遍历数组中的根结点（即前序遍历数组的第一个元素）
            // 它的左边就是要求的二叉树的左子树，右边为右子树；后面的内容就是递归执行这个过程
            if (preorder[0] == inorder[i]) {
                // 构造左子树需要的前序数组和中序数组
                int[] pre_left = Arrays.copyOfRange(preorder, 1, i + 1); // [from, to) 相当于左子树的前序遍历
                int[] in_left = Arrays.copyOfRange(inorder, 0, i);          // 左子树的中序遍历
                // 右子树
                int[] pre_right = Arrays.copyOfRange(preorder, i + 1, n);   // 右子树的前序遍历
                int[] in_right = Arrays.copyOfRange(inorder, i + 1, m);     // 右子树的中序遍历

                //有了上面四个数组，我们就可以开始我们的递归构造二叉树了
                root.left = buildTree(pre_left, in_left);
                root.right = buildTree(pre_right, in_right);
                // 剪枝
                // 我们循环只是为了找到当前需要构造的树的根结点
                break;
            }
        }
        return root;
    }
}