class Solution1147_2 {
    private static long MOD = (long) (1e9 + 7); // 算法（竞赛）中经常选择的大素数
    private static long[] pow26;

    // 使用哈希解决段式回文字符串
    // 这版代码提交上去反而比暴力算的更慢，这是因为力扣官网提供的数据量小
    // 而且我们还要预处理，计算哈希值，所以会更慢
    // 但只要数据量上去了，我们这版代码的速度才能体现出来
    // 之前学习排序的时候也是这样，只有要处理的数据量达到一定量级，nlogn级别的算法才能体现出来优势
    // 这反映我们在现实业务中，要根据数据量的大小选择适合的数据结构和算法，不要盲目最优的，最优的可以慢慢迭代下去再升级
    public static int longestDecomposition(String text) {
        // 预处理数组，用于存储 后面要用到的 26的各个n次方数据
        // 预处理的思想本质上就是用空间换取时间，在时间这么宝贵的情况下，我们是很愿意用空间换时间的
        // 而且前面学过的 Trie 以及红黑树 这些数据结构，也是采用了预处理的思想，先存进去，然后用很短的时间就能拿出来
        pow26 = new long[text.length()];
        pow26[0] = 1;
        for (int i = 1; i < text.length(); i++)
            pow26[i] = pow26[i - 1] * 26 % MOD;

        return solve(text, 0, text.length() - 1);
    }

    // 找 s[left, right] 段中，可以分成多少段回文串
    private static int solve(String s, int left, int right) {
        // 边界条件
        if (left > right)
            return 0;

        // 一个是前面一段字符串的哈希值，另一个是后面一段的哈希值
        long prehash = 0, posthash = 0;
        // 从两端点走，逐个逐个判断是否相等
        for (int i = left, j = right; i < j; i++, j--) {
            // 用我们笔记里推导的公式计算哈希值
            // 另因为 26进制 的数会增长地很快，所以我们最好找一个大素数来防止该哈希值越界
            prehash = (prehash * 26 + (s.charAt(i) - 'a')) % MOD;
            posthash = ((s.charAt(j) - 'a') * pow26[right - j] + posthash) % MOD;

            // 比较 s[left, i] == s[j, right] 哈希值
            // 但是注意，哈希值相等不代表它们就一定相等，因为存在哈希冲突这种情况，所以要再循环判断一次
            // 但别以为这样性能就会更差，我们这里使用了短路操作，只要哈希值不等，就直接中断退出
            if (prehash == posthash && equal(s,left, i, j, right))
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