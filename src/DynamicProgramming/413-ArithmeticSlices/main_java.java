/**
 * 解题思路一：DP
 * 	状态定义：dp[i] 为到第 i 个值时最长等差数列的长度
 * 	状态转移方程：dp[i] = 1 + dp[i-1] if dp[i] - dp[i-1] == dp[i-1] - dp[i-2]
 * 	Boundory Contidion: dp[0] = dp[1] = 0;
 *
 * 最终用 ret 记录 dp[1…n] 的和即可
 */
class Solution413 {
    public static int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        if (n <= 2)
            return 0;

        int ret = 0;
        int[] dp = new int[n];
        dp[0] = dp[1] = 0;

        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                ret += dp[i];
            }
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