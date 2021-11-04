/**
 * 01背包问题
 */
class Solution1049 {
    public int lastStoneWeightII(int[] ss) {
        int n = ss.length;
        int sum = 0;
        for (int i : ss) sum += i;
        int t = sum / 2;
        int[][] f = new int[n + 1][t + 1];

        int i, j, x;
        for (i = 1; i <= n; i++) {
            x = ss[i - 1];
            for (j = 0; j <= t; j++) {
                f[i][j] = f[i - 1][j];
                if (j >= x)
                    f[i][j] = Math.max(f[i][j], f[i - 1][j - x] + x);
            }
        }

        return Math.abs(sum - f[n][t] - f[n][t]);
    }
}