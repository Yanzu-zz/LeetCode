class Solution518_2 {
    public static int change(int cnt, int[] cs) {
        int n = cs.length;
        int[] f = new int[cnt + 1];
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            int val = cs[i - 1];
            for (int j = val; j <= cnt; j++) {
                f[j] += f[j - val];
            }
        }

        return f[cnt];
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 5};
        System.out.println(change(5, arr1));
    }
}