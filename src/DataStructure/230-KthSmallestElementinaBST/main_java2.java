import com.sun.source.tree.Tree;

import java.util.ArrayDeque;
import java.util.Deque;

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

class Solution230_1_2 {
    // 中序遍历一颗二叉树得到的值是顺序增长的
    public int kthSmallest(TreeNode root, int k) {
        // 我们自己定义栈来模拟迭代
        Deque<TreeNode> stack = new ArrayDeque<>();
        int currSmallthVal = 0, ret = Integer.MIN_VALUE;
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.push(root); // 这里相当于 递归左子树
                root = root.left;
            }
            root = stack.pop();
            currSmallthVal++;
            if (currSmallthVal == k) {
                ret = root.val;
                break;
            }
            root = root.right; // 递归右子树
        }

        return ret;
    }
}