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

class Solution124 {
    private int ret = Integer.MIN_VALUE;

    private int dfs(TreeNode curr) {
        if (curr == null)
            return 0;

        // 计算左边分支最大值，如果为负数还不如不选择
        int leftMax = Math.max(0, dfs(curr.left));
        // 右边同理
        int rightMax = Math.max(0, dfs(curr.right));

        // 接着就是更新最大值了
        ret = Math.max(ret, curr.val + leftMax + rightMax);
        // 当前节点的最大路径计算完毕，接下来就是传递当前值回溯给父结点使用了
        return curr.val + Math.max(leftMax, rightMax);
    }

    public int maxPathSum(TreeNode root) {
        if (root == null)
            return 0;

        dfs(root);
        return max;
    }
}