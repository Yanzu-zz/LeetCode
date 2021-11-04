import java.util.Arrays;

class Solution307 {
    private int[] data; // nums 数组拷贝
    private int[] blocks; // 计算每个 sqrt 分组的和
    private int N; // 元素总数
    private int B; // 每组元素的个数
    private int Bn; // 分的组数

    public Solution307(int[] nums) {
        N = nums.length;
        if (N == 0)
            return;

        // 向下取整分组个数
        B = (int) Math.sqrt(N);
        Bn = N / B + (N  B > 0 ? 1 : 0);

        data = Arrays.copyOf(nums, N);
        blocks = new int[Bn];
        for (int i = 0; i < N; i++) // 初始化区间值
            blocks[i / B] += nums[i];
    }

    public int sumRange(int x, int y) {
        if (x < 0 || x >= N || y < 0 || y >= N || x > y)
            return 0;

        int res = 0; // 最终计算值
        // 求对应组号
        int bStart = x / B, bEnd = y / B;

        // 如果开头结尾在同一组的情况
        if (bStart == bEnd) {
            for (int i = x; i <= y; i++)
                res += data[i];
            return res;
        }

        // 不在同一组的情况
        // 首先遍历最前面的数组
        for (int i = x; i < (bStart + 1) * B; i++)
            res += data[i];
        // 其次如果中间相邻，则加上预设好的组和 blocks 数组中的值
        // 如果中间没有则不会执行逻辑
        for (int b = bStart + 1; b < bEnd; b++)
            res += blocks[b];
        // 最后遍历最后面的数组
        for (int i = bEnd * B; i <= y; i++)
            res += data[i];

        return res;
    }

    // 更新单个值，并把该值所属的组的和更新
    public void update(int i, int val) {
        if (i < 0 || i >= N)
            return;

        int b = i / B; // 找到该元素的组
        // 更新该组的和
        blocks[b] -= data[i];
        blocks[b] += val;

        data[i] = val;
    }
}
