import java.util.Arrays;

/**
 * 解题思路一：暴力
 * 既然是统计 [0, n] 各个数字的二进制的 1 的数量，就循环 0-n 然后用位操作统计每个数字对应的数量即可
 */
class Solution338 {
    public static int[] countBits(int n) {
        int ret[] = new int[n + 1];
        int t1, t2, count;
        for (int i = 0; i <= n; i++) {
            t1 = i;
            count = 0;
            while (t1 > 0) {
                t2 = t1 & 1;
                if (t2 == 1)
                    count++;
                t1 >>= 1;
            }

            ret[i] = count;
        }

        return ret;
    }

    public static void main(String[] args) {
        int n1 = 2;
        int n2 = 8;

        int ret1[] = countBits(n1);
        int ret2[] = countBits(n2);

        System.out.println(Arrays.toString(ret1));
        System.out.println(Arrays.toString(ret2));
    }
}