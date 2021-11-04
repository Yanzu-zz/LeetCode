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

class Solution230 {
    private int currSmallthVal = 0;
    private int ret = Integer.MIN_VALUE;

    // 中序遍历一颗二叉树得到的值是顺序增长的
    private void inorder(TreeNode root, int k) {
        if (root == null || ret != Integer.MIN_VALUE)
            return;

        inorder(root.left, k);
        currSmallthVal++; // 记录当前第几个最小元素
        if (currSmallthVal == k)
            ret = root.val;
        inorder(root.right, k);
    }

    public int kthSmallest(TreeNode root, int k) {
        inorder(root, k);
        return ret;
    }
}