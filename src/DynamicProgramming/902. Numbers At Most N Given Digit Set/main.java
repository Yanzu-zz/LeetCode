class Solution {
    public int atMostNGivenDigitSet(String[] digits, int n) {
        char[] nc = String.valueOf(n).toCharArray();
        int result = 0, ncl = nc.length, dl = digits.length;
        for (int i = 1; i < ncl; i++) result += Math.pow(dl, i); // 先对【非最高位】的其他位，可组装的数字进行统计
        for (int i = 0; i < ncl; i++) {
            boolean compareNext = false; // 是否需要对比下一个数字
            for (String digit : digits) {
                char dc = digit.charAt(0); // 将String转换为char
                if (dc < nc[i]) result += Math.pow(dl, ncl - i - 1);
                else {
                    if (dc == nc[i]) compareNext = true; break;
                }
            }
            if (!compareNext) return result;
        }
        return ++result; // 如果到最后1位依然满足compareNext，因为最后1位无法再向后对比了，所以最终结果+1
    }
}
