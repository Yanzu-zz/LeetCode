import java.util.Arrays;

// 思路有问题
class Solution85_xxxx {
    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length;
        if (n == 0)
            return 0;

        int m = matrix[0].length;
        int[][] dp = new int[n][m];
        int[][] w = new int[n][m];
        int[][] h = new int[n][m];

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    w[i][j] = 0;
                    h[i][j] = 0;
                    continue;
                }

                w[i][j] = 1;
                h[i][j] = 1;
                int a = 1, b = 1, c = 0; // 左边元素和上边元素

                if (i == 0 && j > 0) { // 第一行的情况
                    a = matrix[i][j - 1] - '0'; // 这时候只能是有左边元素了
                    if (a != 0)
                        w[i][j] = w[i][j - 1] + 1;
                } else if (i > 0 && j == 0) { // 在第一列的情况
                    b = matrix[i - 1][j] - '0'; // 此时只能有上方元素
                    if (b != 0)
                        h[i][j] = h[i - 1][j] + 1;
                }
                // 不是第一行或第一列的情况
                else if (i > 0 && j > 0) { // 不在左上边界处才能进行 dp 操作
                    a = matrix[i][j - 1] - '0'; // 左边元素
                    b = matrix[i - 1][j] - '0'; // 上面元素
                    c = matrix[i - 1][j - 1] - '0';

                    if (a != 0)
                        w[i][j] = w[i][j - 1] + 1;
                    if (b != 0)
                        h[i][j] = h[i - 1][j] + 1;
                }

                maxArea = Math.max(maxArea, dp[i][j]);
            }
        }

        return maxArea;
    }
}