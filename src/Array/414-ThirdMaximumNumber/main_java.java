import java.util.Arrays;

class Solution414 {
    public int thirdMax(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = n - 2, cnt = 1; i >= 0; i--) {
            if (nums[i] != nums[i + 1] && ++cnt == 3)
                return nums[i];
        }

        return nums[n - 1];
    }
}