import com.sun.source.tree.Tree;

import java.util.*;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        // return _serialize(root, "");
        StringBuilder sb = new StringBuilder();
        _serialized(root, sb);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] dataArray = data.split(",");
        List<String> dataList = new LinkedList<>(Arrays.asList(dataArray));
        return _deserialize(dataList);
    }

    /*public String _serialize(TreeNode root, String str) {
        if (root == null) {
            return str += "None,";
        } else {
            str += String.valueOf(root.val) + ",";
            str = _serialize(root.left, str);
            str = _serialize(root.right, str);
        }

        return str;
    }*/
    public void _serialized(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append("None,");
        } else {
            sb.append(String.valueOf(root.val)).append(",");
            _serialized(root.left, sb);
            _serialized(root.right, sb);
        }
    }

    public TreeNode _deserialize(List<String> dataList) {
        if (dataList.get(0).equals("None")) {
            dataList.remove(0);
            return null;
        }

        TreeNode root = new TreeNode(Integer.parseInt(dataList.get(0)));
        dataList.remove(0);
        root.left = _deserialize(dataList);
        root.right = _deserialize(dataList);

        return root;
    }
}