import java.util.Arrays;

class Solution279 {
    public static int numSquares(int n) {
        int i, j;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n);
        dp[0] = 0;
        dp[1] = 1;
        for (i = 2; i <= n; i++)
            for (j = (int) Math.sqrt(i); j > 0; j--)
                dp[i] = Math.min(dp[i], dp[i - j * j] + 1);

        return dp[n];
    }

    public static void main(String[] args) {
        int n1 = 12;
        System.out.println(numSquares(n1));

        int n2 = 13;
        System.out.println(numSquares(n2));
    }
}