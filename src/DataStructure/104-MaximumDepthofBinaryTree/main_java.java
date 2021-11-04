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

class Solution104 {
    private int ret = 0;

    private void dfs(TreeNode curr, int currLevel) {
        if (curr == null) {
            ret = Math.max(ret, currLevel);
            return;
        }

        dfs(curr.left, currLevel + 1);
        dfs(curr.right, currLevel + 1);
    }

    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;

        // 从 0 开始是因为我们的代码是会在 null 层计算结果，故需要初始化-1
        dfs(root, 0);
        return ret;
    }
}