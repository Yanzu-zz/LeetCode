import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    int len;

    public List<String> removeInvalidParentheses(String s) {
        char[] cs = s.toCharArray();

        // 统计左右括号数量
        int l = 0, r = 0;
        for (char c : cs) {
            if (c == '(')
                l++;
            else if (c == ')')
                r++;
        }
        int max = Math.min(l, r);
        Set<String> all = new HashSet<>();

        // 开始【爆搜】
        dfs(cs, 0, 0, max, "", all);

        // 【爆搜】的结果存在 all 中，我们取括号匹配正常的
        List<String> ans = new ArrayList<>();
        for (String str : all)
            if (str.length() == len)
                ans.add(str);

        return ans;
    }

    /**
     * cs: 字符串 s 对应的字符数组
     * u: 当前决策到 cs 的哪一位
     * score: 当前决策方案的得分值（每往 cur 追加一个左括号进行 +1；每往 cur 追加一个右括号进行 -1）
     * max: 整个 dfs 过程的最大得分
     * cur: 当前决策方案
     * ans: 合法方案结果集
     */
    void dfs(char[] cs, int u, int score, int max, String cur, Set<String> ans) {
        // 边界条件
        if (u == cs.length) {
            if (score == 0 && cur.length() >= len) {
                len = Math.max(len, cur.length());
                ans.add(cur);
            }
            return;
        }

        if (cs[u] == '(') {
            // 尝试加右括号
            if (score + 1 <= max)
                dfs(cs, u + 1, score + 1, max, cur + "(", ans);
            // 不加右括号
            dfs(cs, u + 1, score, max, cur, ans);
        } else if (cs[u] == ')') {
            // 尝试加左括号
            if (score > 0)
                dfs(cs, u + 1, score - 1, max, cur + ")", ans);
            // 不加左括号
            dfs(cs, u + 1, score, max, cur, ans);
        } else { // 其它字符情况，保留就好
            dfs(cs, u + 1, score, max, cur + String.valueOf(cs[u]), ans);
        }
    }
}