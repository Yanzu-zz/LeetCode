class Solution79 {
    private final static int[][] direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    private boolean dfs(char[][] board, String word, boolean[][] visited, int currLen, int i, int j) {
        // 剪枝，当前位置的字符与所求字符串位置字符不同，则无需浪费时间继续
        if (board[i][j] != word.charAt(currLen))
            return false;
            // 这里则是找到了所求字符
        else if (currLen == word.length() - 1)
            return true;

        visited[i][j] = true;
        for (int[] dir : direction) {
            int newI = i + dir[0], newJ = j + dir[1];
            // 查看即将要探索的点位是否合法（如是否在board内）
            if (newI >= 0 && newI < board.length && newJ >= 0 && newJ < board[0].length) {
                if (visited[newI][newJ])
                    continue;

                boolean flag = dfs(board, word, visited, currLen + 1, newI, newJ);
                if (flag)
                    return true;
            }
        }

        visited[i][j] = false;
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int n = board.length, m = board[0].length;
        boolean[][] visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                boolean flag = dfs(board, word, visited, 0, i, j);
                if (flag)
                    return true;
            }
        }

        return false;
    }
}