class Solution240 {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length, m = matrix[0].length;
        int currRow = n - 1, currCol = 0; // 用来指示我们指针的行列变量，初始位置为左下角

        /**
         * 如果当前指向的值大于目标值，则可以 “向上” 移动一行。
         * 否则，如果当前指向的值小于目标值，则可以向右移动一列。
         *
         * 因为我们的指针只能 向上、向右走，故我们这样判断就行
         */
        while (currRow >= 0 && currCol < m) {
            int currVal = matrix[currRow][currCol];
            if (currVal == target)
                return true;
            else if (currVal > target)
                currRow--;
            else
                currCol++;
        }

        return false;
    }
}