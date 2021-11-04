package a1;

// 深搜超时
class Solution62 {
    private static int N, M;
    private static final int[][] d = {{0, 1}, {1, 0}};
    private static boolean[][] visited;
    private static int differentPath;

    public static int uniquePaths(int m, int n) {
        N = n;
        M = m;
        visited = new boolean[N][M];
        differentPath = 0;

        visited[0][0] = true;
        dfs(0, 0);

        return differentPath;
    }

    private static void dfs(int x, int y) {
        if (x == N - 1 && y == M - 1) {
            differentPath++;
            return;
        }

        for (int i = 0; i < d.length; i++) {
            int newX = x + d[i][0];
            int newY = y + d[i][1];

            if (inMap(newX, newY) && !visited[newX][newY]) {
                dfs(newX, newY);
                visited[newX][newY] = false;
            }
        }
    }

    private static boolean inMap(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    public static void main(String[] args) {
        int ret1 = uniquePaths(3, 3);
        System.out.println(ret1);

        int ret2 = uniquePaths(3, 7);
        System.out.println(ret2);
    }
}
