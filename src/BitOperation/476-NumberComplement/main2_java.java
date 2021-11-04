class Solution476 {
    public int findComplement(int num) {
        int x = 0;
        // 这里的作用是求得 num 二进制表示中最高位是 1 的位置
        for (int i = num; i != 0; i -= i & -i)
            x = i;

        return ~num & (x - 1);
    }
}