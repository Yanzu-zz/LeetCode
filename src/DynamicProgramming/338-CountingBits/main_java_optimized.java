import java.util.Arrays;

class Solution338_1 {
    public static int[] countBits(int n) {
        int ret[] = new int[n + 1];

        for (int i = 0; i <= n; i++)
            ret[i] = Integer.bitCount(i);

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