/**
 * 解题思路二：DP
 * 在上一节基础上我们看到，整个dp核心就是 dp[i] 和 dp[i-1] 故我们用2个滚动变量记录即可
 * 我们社 a = dp[i], b = dp[i-1]
 */
class Solution413_2 {
    public static int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        if (n <= 2)
            return 0;

        int ret = 0;
        int i, a = 0, b = 0;

        for (i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                a = b + 1;
                ret += a;
            } else {
                a = 0;
            }

            // 开始滚动
            b = a;
        }

        return ret;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4};
        System.out.println(numberOfArithmeticSlices(arr1));

        int[] arr2 = {1, 2, 3, 4, 5};
        System.out.println(numberOfArithmeticSlices(arr2));
    }
}