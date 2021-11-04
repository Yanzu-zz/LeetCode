import java.util.Arrays;

class Solution650 {
    public static int minSteps(int n) {
        int N = Math.max(n, 3);
        // 开始dp少操作步骤
        int[] dp = new int[N + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[1] = 0;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            // double x = Math.ceil(Math.sqrt((double) i));
            int x = i / 2;
            for (int j = 2; j <= x; j++) {
                if (i % j == 0)
                    dp[i] = Math.min(dp[j] + (i / j), dp[i]); // dp 公式在笔记里
            }
            if (dp[i] == Integer.MAX_VALUE)
                dp[i] = i;
        }

        return dp[n];
    }

    public static void main(String[] args) {
        for (int i = 1; i <= 12; i++)
            System.out.println(i + ": " + minSteps(i));
    }
}