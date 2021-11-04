class Solution476 {
    public int findComplement(int num) {
        int bitStartIdx = 31;
        for (int i = 31; i >= 0; i--) {
            // 重点就是找到第一个不为 0 的位置
            if (((num >> i) & 1) != 0) {
                bitStartIdx = i;
                break;
            }
        }

        // 接下来就是做翻转运算了
        int ans = 0;
        for (int i = 0; i < bitStartIdx; i++) {
            if (((num >> i) & 1) == 0) // 第 i 个位置上的值为 0 才管它，否则 1 自己会变0（定义的ans初始为0）
                ans |= (1 << i);
        }

        return ans;
    }
}