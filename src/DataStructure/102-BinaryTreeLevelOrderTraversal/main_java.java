import java.util.*;

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

class Solution102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (root == null)
            return ret;

        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        while (!q.isEmpty()) {
            List<Integer> tmp = new ArrayList<>();
            int currLevelSize = q.size();
            // 每次只遍历当前节点的 子结点数量
            for (int i = 0; i < currLevelSize; i++) {
                TreeNode firstNode = q.poll();
                tmp.add(firstNode.val);
                if (firstNode.left != null)
                    q.offer(firstNode.left);
                if (firstNode.right != null)
                    q.offer(firstNode.right);
            }
            ret.add(tmp);
        }

        return ret;
    }
}