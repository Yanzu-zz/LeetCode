class Solution1147 {
    // 不使用哈希解决段式回文字符串
    public static int longestDecomposition(String text) {
        return solve(text, 0, text.length() - 1);
    }

    // 找 s[left, right] 段中，可以分成多少段回文串
    private static int solve(String s, int left, int right) {
        // 边界条件
        if (left > right)
            return 0;

        // 从两端点走，逐个逐个判断是否相等
        for (int i = left, j = right; i < j; i++, j--) {
            // 如果我们发现 s[left, i] == s[j, right] 是相等的话，那我们就相当于找到了 2 段回文字符串
            // 因为相同的字符串在前后是算2段的
            if (equal(s, left, i, j, right))
                // 找到了就继续递归下，想法和动态规划是很相近的
                return 2 + solve(s, i + 1, j - 1);
        }

        // 如果到头了都没有能找到回文串，那就表明这段字符不能再分了，只有它自己本身就是一个会问出
        return 1;
    }

    // 判断 s[l1, r1] 是否等于 s[l2, r2] （区间字符串）
    private static boolean equal(String s, int l1, int r1, int l2, int r2) {
        for (int i = l1, j = l2; i <= r1 && j <= r2; i++, j++)
            if (s.charAt(i) != s.charAt(j))
                return false;

        return true;
    }

    public static void main(String[] args) {
        String s1 = "ghiabcdefhelloadamhelloabcdefghi";
        System.out.println(longestDecomposition(s1));
    }
}