class Solution5882_2 {
    public long gridGame(int[][] grid) {
        int m = grid[0].length;
        long[][] pre = new long[2][m + 1]; // 前缀和
        for (int j = 1; j <= m; j++) {
            pre[0][j] = pre[0][j - 1] + grid[0][j - 1];
            pre[1][j] = pre[1][j - 1] + grid[1][j - 1];
        }

        long ret = Long.MAX_VALUE;
        // 这里的目标是找到两条蓝线中的最小值（循环就是要逐个逐个找，这里可以抽象成一次就行）
        for (int j = 1; j <= m; j++)
            // 第一条蓝线前面至少会少一个格子（初始点[0][0]），下面也可能少一个格子（终点[1][m-1]）
            // 两条蓝线的计算方式不一样而已
            ret = Math.min(ret, Math.max(pre[0][m - 1] - pre[0][j], pre[1][j - 1]));

        return ret;
    }
}