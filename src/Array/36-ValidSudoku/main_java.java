import java.util.HashSet;

class Solution36 {
    public boolean isValidSudoku(char[][] board) {
        int n = 9, m = 10; // n 为数独行列数，m 为 0-9 十个数字的长度
        boolean[][] row = new boolean[n][m]; // row[i][j] 表示第i行是否有 数字j
        boolean[][] col = new boolean[n][m]; // col[i][j] 同理
        // 九宫格顺序为 从左到右，从上到下
        boolean[][] box = new boolean[n][m]; // box[i][j] 表示第 i 个3x3九宫格是否包含 数字j

        // 开始一次遍历搞定所有
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { // 注意这里 n 代表着行列数，所以 j 要和 n 做判断
                if (board[i][j] == '.')
                    continue;

                int curNum = board[i][j] - '0'; // 获取当前位置的数独值
                int boxPos = (j / 3) + (i / 3) * 3; // 其实最关键就是这个获取当前区域是第几个九宫格的公式！！
                // 判断是否存在
                if (row[i][curNum] || col[j][curNum] || box[boxPos][curNum])
                    return false;

                // 记录这个数字在对应位置出现过
                row[i][curNum] = true; // 行位置
                col[j][curNum] = true; // 列位置
                box[boxPos][curNum] = true; // 九宫格位置
            }
        }

        return true;
    }
}