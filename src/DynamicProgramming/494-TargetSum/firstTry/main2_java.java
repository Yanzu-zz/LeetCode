/**
 * 方法二：动态规划
 * 	能够以[递归]的形式实现动态规划（记忆化搜索），自然也能使用[递推]的方式进行实现。
 * 	根据记忆化搜索的分析，我们可以定义：
 * 	f[[j]代表考虑前i个数，当前计算结果为j的方案数，令nums 下标从1开始。
 * 	那么f[n]ltarget]为最终答案，f[o][0]=1为初始条件：代表不考虑任何数，凑出计算结果为0的方案数为1种。
 * 	根据每个数值只能搭配+/-使用，可得状态转移方程：
 * 		f[[i]=fi-1]li-nums[i-1]]+fi-1][i+nums[i-1]]
 *
 * 	到这里，既有了[状态定义」和[转移方程」，又有了可以滚动下去的[有效值]（起始条件）。
 * 	距离我们完成所有分析还差最后一步。
 * 	当使用递推形式时，我们通常会使用[静态数组]来存储动规值，因此还需要考虑维度范围的：
 * 	·第一维为物品数量：范围为nums数组长度
 * 	·第二维为中间结果：令s为所有nums元素的总和（题目给定了nums[i]为非负数的条件，否则需要对nums[i]取绝对值再累加），那么中间结果的范围为[-s，s]
 * 	因此，我们可以确定动规数组的大小。同时在转移时，对第二维度的使用做一个s的右偏移，以确保[负权值]也能够被合理计算/存储。
 */
class Solution494_3 {
    public static int findTargetSumWays(int[] nums, int t) {
        int n = nums.length;
        int s = 0;
        for (int i : nums) s += Math.abs(i);
        if (t > s) return 0;
        int[][] f = new int[n + 1][2 * s + 1];
        f[0][0 + s] = 1;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            for (int j = -s; j <= s; j++) {
                if ((j - x) + s >= 0) f[i][j + s] += f[i - 1][(j - x) + s];
                if ((j + x) + s <= 2 * s) f[i][j + s] += f[i - 1][(j + x) + s];
            }
        }
        return f[n][t + s];
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 1, 1, 1, 1};
        int t1 = 3;
        System.out.println(findTargetSumWays(arr1, t1));
    }
}