package Array;

class Solution48 {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int i, j, temp;

        // 先水平翻转（上下翻转）
        for (i = 0; i < n / 2; i++) {
            for (j = 0; j < n; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = temp;
            }
        }

        // 接着主对角线翻转
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 这样就能实现顺时针90°翻转效果
    }
}