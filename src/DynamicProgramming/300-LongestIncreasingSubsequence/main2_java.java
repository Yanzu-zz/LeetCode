import java.util.*;

class Solution300_2 {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        List<Integer> cell = new ArrayList<>();
        cell.add(nums[0]);

        for (int i = 1; i < n; i++) {
            int len = cell.size();
            if (nums[i] > cell.get(len - 1)) { // 如果比队尾元素大则直接入队
                cell.add(nums[i]);
            } else { // 否则覆盖当前数组中比它大的数的最小的那个位置上
                int l = 0, r = len - 1;
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (cell.get(mid) < nums[i])
                        l = mid + 1;
                    else
                        r = mid;
                }
                cell.set(r, nums[i]);
            }
        }

        return cell.size();
    }
}