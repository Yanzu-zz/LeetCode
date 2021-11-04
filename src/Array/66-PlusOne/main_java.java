import java.util.Arrays;

class Solution66 {
    public int[] plusOne(int[] digits) {
        int n = digits.length - 1;
        boolean carry = true;
        final int addNum = 1;

        // 只要当前位置有进位情况，就一直加下去；否则就退出了
        while (carry && n >= 0) {
            digits[n] += addNum;
            if (digits[n] >= 10) {
                digits[n] %= 10;
                n--;
            } else {
                carry = false;
            }
        }

        // 最高位要进1的情况（carry 还为true表示当前数字是n个99999这种类型）
        if (carry) {
            int[] ans = new int[digits.length + 1];
            ans[0] = 1;
            return ans;
        }

        return digits;
    }
}