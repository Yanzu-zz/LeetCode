import java.util.Arrays;

class Solution287 {
    public int findDuplicate(int[] nums) {
        int n = nums.length, i = 0;

        // 排序后遍历判断是否重复即可
        Arrays.sort(nums);
        for (; i < n - 1 && nums[i] != nums[i + 1]; i++) ;

        return nums[i];
    }
}