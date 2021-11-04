import java.util.HashMap;
import java.util.Map;

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

class Solution437_2 {
    private int target, ret = 0;
    private Map<Integer, Integer> map;

    private void _pathSum(TreeNode root, int currVal) {
        if (root == null)
            return;

        // 记录当前前缀和
        currVal += root.val;
        // 如果有相应的结点的话，路径+1
        ret += map.getOrDefault(currVal - target, 0);

        // 继续递归下去寻找
        // 当然记得记录下这个结点的值
        map.put(currVal, map.getOrDefault(currVal, 0) + 1);
        _pathSum(root.left, currVal);
        _pathSum(root.right, currVal);
        map.put(currVal, map.getOrDefault(currVal, 0) - 1);
        // ↑↑↑ 当然完了记得回溯状态
    }

    public int pathSum(TreeNode root, int targetSum) {
        target = targetSum;
        map = new HashMap<>();
        map.put(0, 1);
        _pathSum(root, 0);

        return ret;
    }
}