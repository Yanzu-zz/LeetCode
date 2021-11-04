import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution15 {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        if (len < 3)
            return ans;

        Arrays.sort(nums);
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) break; // 排过序后的数组元素大于0的话是不可能加起来得0的
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重

            int L = i + 1, R = len - 1; // 左右指针
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) { // 找到 3 sums 了
                    ans.add(Arrays.asList(nums[i], nums[L], nums[R]));
                    while (L < R && nums[L] == nums[L + 1]) L++; // 去重
                    while (L < R && nums[R] == nums[R - 1]) R--; // 去重
                    L++;
                    R--;
                }
                // 因为是排过序的，过大过小调整下指针位置即可
                else if (sum < 0) L++;
                else if (sum > 0) R--;
            }
        }

        return ans;
    }
}