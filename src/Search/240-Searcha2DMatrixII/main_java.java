class Solution240 {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length, m = matrix[0].length;
        int rowEndIdx = 0, colEndIdx = 0; // 行列结束索引（因为题目说了按照升序排序）

        // 查询行结束索引位置
        for (int i = 0; i < n && matrix[i][0] <= target; i++) {
            if (matrix[i][0] == target)
                return true;
            rowEndIdx++;
        }
        // 查询列结束索引位置
        for (int j = 0; j < m && matrix[0][j] <= target; j++) {
            if (matrix[0][j] == target)
                return true;
            colEndIdx++;
        }

        // 开始二分
        for (int i = 0; i < rowEndIdx; i++) {
            int left = 0, right = colEndIdx;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] < target)
                    left = mid + 1;
                else
                    right = mid;
            }
        }

        return false;
    }
}