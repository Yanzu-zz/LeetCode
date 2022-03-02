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

class Solution230_2 {
    public int kthSmallest(TreeNode root, int k) {
        MyBst mb = new MyBst(root);
        return mb.kthSmallest(k);
    }
}

class MyBst {
    TreeNode root;
    Map<TreeNode, Integer> nodeNum; // 记录每个节点有多少个子树节点的map

    public MyBst(TreeNode root) {
        this.root = root;
        nodeNum = new HashMap<>();
        countNodeNum(root);
    }

    // 返回二叉搜索树中第 k 小的元素
    public int kthSmallest(int k) {
        TreeNode node = root;
        while (node != null) {
            int left = getNodeNum(node.left);
            if (left < k - 1) { // 左边节点数量比 k 小，说明要找的元素肯定在右边
                node = node.right;
                k -= left + 1;
            } else if (left == k - 1) { // 这个表明当前节点就是要找的
                break;
            } else { // 否则肯定在左子树里面
                node = node.left;
            }
        }
        return node.val;
    }

    // 统计以 node 为根结点的子树的节点数
    private int countNodeNum(TreeNode node) {
        if (node == null)
            return 0;

        nodeNum.put(node, 1 + countNodeNum(node.left) + countNodeNum(node.right));
        return nodeNum.get(node);
    }

    // 获取以node为根结点的子树的结点数
    private int getNodeNum(TreeNode node) {
        return nodeNum.getOrDefault(node, 0);
    }
}