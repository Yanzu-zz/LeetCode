package Array;

class Solution53 {
    // 动态规划解法
    /*public static int maxSubArray(int[] nums) {
        // dp[i] 表示前i个连续子数组的最大和
        int ret = Integer.MIN_VALUE;
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            // 这样写保证连续 这才是正确的状态方程
            dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > ret)
                ret = dp[i];
        }

        return ret;
    }*/

    // 贪心解法
    public static int maxSubArray(int[] nums) {
        int ret = Integer.MIN_VALUE;
        int subSum = 0;
        for (int i = 0; i < nums.length; i++) {
            subSum += nums[i];
            if (subSum > ret)
                ret = subSum;

            if (subSum < 0)
                subSum = 0;
        }

        return ret;
    }

    public static void main(String[] args) {
        int[] arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int ret1 = maxSubArray(arr1);
        System.out.println(ret1);

        int[] arr2 = {5, 4, -1, 7, 8};
        int ret2 = maxSubArray(arr2);
        System.out.println(ret2);
    }
}
