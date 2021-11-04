class Solution1143 {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length(), m = text2.length();
        int[][] dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 找到了一个相同的字符，故当前位置记录的最长子序列长度 + 1
                // TIP: 子序列可以是不连续的
                if (text1.charAt(i - 1) == text2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else // 否则延续前面的最长子序列长度
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m]; // 最后位置就是两个字符串的最长子序列长度了
    }
}