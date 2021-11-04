class Solution5882 {
    int n, m;
    int maxVal = 0;
    public boolean[][] visited;
    private static final int[][] d = {{0, 1}, {1, 0}};

    private void dfs(int x, int y, int currVal, int[][] grid) {
        visited[x][y] = true; // 用来置0的
        if (x == 1 && y == m - 1 && currVal > maxVal) {
            maxVal = currVal;
            return;
        }

        for (int i = 0; i < 2; i++) {
            int newX = x + d[i][0];
            int newY = y + d[i][1];

            // 确保没越界
            if (newX <= 1 && newY < m && !visited[newX][newY]) {
                dfs(newX, newY, currVal + grid[newX][newY], grid);
            }
        }

        visited[x][y] = false;
    }

    public long gridGame(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        visited = new boolean[n][m];
        dfs(0, 0, grid[0][0], grid);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (visited[i][j])
                    grid[i][j] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                System.out.print(grid[i][j]);
            System.out.println();
        }

        int[][] dp = new int[n][m];
        dp[0][0] = grid[0][0];
        dp[1][0] = grid[1][0];
        for (int j = 1; j < m; j++)
            dp[0][j] += grid[0][j - 1];

        for (int j = 1; j < m; j++)
            dp[1][j] = Math.max(dp[0][j] + grid[1][j], dp[1][j - 1] + grid[1][j]);

        return dp[n - 1][m - 1];
    }
}