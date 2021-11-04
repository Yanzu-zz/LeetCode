import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution78 {
    private void backtrack(int i, int[] nums, List<List<Integer>> ret, List<Integer> curr) {
        ret.add(new ArrayList<>(curr));
        for (int j = i; j < nums.length; j++) {
            curr.add(nums[j]); // 考虑当前字母
            backtrack(j + 1, nums, ret, curr); // 下一轮递归
            curr.remove(curr.size() - 1); // 不考虑当前字母
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();
        backtrack(0, nums, ret, new ArrayList<>());

        return ret;
    }
}