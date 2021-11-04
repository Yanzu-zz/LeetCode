class Solution337 {
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

    private int[] robInternal(TreeNode root) {
        int[] ret = new int[2];
        if (root == null)
            return ret;

        // 后序遍历
        int[] left = robInternal(root.left);
        int[] right = robInternal(root.right);

        // 开始计算最大利润
        ret[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]); // don't rob
        ret[1] = left[0] + right[0] + root.val;

        return ret;
    }

    public int rob(TreeNode root) {
        int result[] = robInternal(root);
        return Math.max(result[0], result[1]);
    }

    public static void main(String[] args) {

    }
}