class Solution85 {
    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length;
        if (n == 0)
            return 0;

        int m = matrix[0].length;
        int[][] width = new int[n][m];
        int maxArea = 0; // 最终所求的最大矩形面积
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 更新 width
                if (matrix[i][j] == '1') {
                    if (j == 0) // 第一列没有左边
                        width[i][j] = 1;
                    else        // 剩下的都可以正常取
                        width[i][j] = width[i][j - 1] + 1;
                } else {
                    width[i][j] = 0;
                }

                // 记录所有行中最小的数
                int minWidth = width[i][j];
                // 向上扩展行，查看以当前位置为右下角的矩形最大面积能多大
                for (int up_row = i; up_row >= 0; up_row--) {
                    int height = i - up_row + 1; // 矩形高度
                    minWidth = Math.min(minWidth, width[up_row][j]); // 矩形宽度

                    maxArea = Math.max(maxArea, minWidth * height); // 更新最大面积
                }
            }
        }

        return maxArea;
    }
}