/**
 * 方法一：回溯
 * 数组nums的每个元素都可以添加符号+或-，因此每个元素有2种添加符号的方法，n个数共有2n种添加符号的方法，对应20种不同的表达式。当n个元素都添加符号之后，即得到一种表达式，如果表达式的结果等于目标数target，则该表达式即为符合要求的表达式。
 * 可以使用回溯的方法遍历所有的表达式，回溯过程中维护一个计数器count，当遇到一种表达式的结果等于目标数target时，将count的值加1。遍历完所有的表达式之后，即可得到结果等于目标数target的表达式的数目。
 */
class Solution494_2_2 {
    public static int findTargetSumWays(int[] nums, int t) {
        int n = nums.length;
        int s = 0;
        for (int i : nums) s += Math.abs(i);
        if (t > s || (s - t) % 2 != 0) return 0;
        int m = (s - t) / 2;
        int[][] f = new int[n + 1][m + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            for (int j = 0; j <= m; j++) {
                f[i][j] += f[i - 1][j];
                if (j >= x) f[i][j] += f[i - 1][j - x];
            }
        }
        return f[n][m];
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 1, 1, 1, 1};
        int t1 = 3;
        System.out.println(findTargetSumWays(arr1, t1));
    }
}