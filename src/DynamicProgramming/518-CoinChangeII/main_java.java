class Solution518 {
    public static int change(int amount, int[] coins) {
        int n = coins.length;
        int[][] f = new int[n + 1][amount + 1];
        f[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            int val = coins[i - 1];
            for (int j = 0; j <= amount; j++) {
                f[i][j] = f[i - 1][j];
                for (int k = 1; k * val <= j; k++) {
                    f[i][j] += f[i - 1][j - k * val];
                }
            }
        }

        return f[n][amount];
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 5};
        System.out.println(change(5, arr1));
    }
}