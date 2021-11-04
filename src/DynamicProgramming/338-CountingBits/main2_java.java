import java.util.Arrays;

/**
 * 解题思路二：DP
 * 对于所有的数字，只有两类：
 * 奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 + 1
 * 偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的
 * boundary condition: 0 的 1 个数为 0，于是就可以根据奇偶性开始遍历计算了。
 */
class Solution338_2 {
    public static int[] countBits(int n) {
        int ret[] = new int[n + 1];
        ret[0] = 0;

        for (int i = 1; i <= n; i++)
            ret[i] = i % 2 == 0 ? ret[i / 2] : ret[i - 1] + 1;

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