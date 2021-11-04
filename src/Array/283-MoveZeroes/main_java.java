import java.util.Arrays;

class Solution283 {
    private void swap(int[] nums, int l, int r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }

    public void moveZeroes(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return;

        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] == 0)
                swap(nums, left, right--); // 交换时左指针不懂，右指针向前走
            left++;
        }

        Arrays.sort(nums, 0, right);
    }
}