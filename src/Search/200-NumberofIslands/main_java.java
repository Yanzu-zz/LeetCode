class Solution200 {
    private int n, m;
    private boolean[][] visited;
    private final static int[][] direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    private void dfs(char[][] grid, int i, int j) {
        visited[i][j] = true; // 把该岛屿地方“染色”

        // 下面就是正常 dfs 逻辑了
        for (int k = 0; k < direction.length; k++) {
            int newI = i + direction[k][0];
            int newJ = j + direction[k][1];
            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m &&
                    !visited[newI][newJ] &&
                    grid[newI][newJ] == '1')
                dfs(grid, newI, newJ);
        }
    }

    public int numIslands(char[][] grid) {
        n = grid.length;
        m = grid[0].length;
        visited = new boolean[n][m];

        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1'){ // 发现新岛屿
                    ret++;           // 岛屿数量+1
                    dfs(grid, i, j); // 把该岛屿全部染色
                }
            }
        }

        return ret;
    }
}