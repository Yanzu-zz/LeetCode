import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution524_3 {
    public static String findLongestWord(String s, List<String> dictionary) {
        // 先 dp 预先处理 s dp[i][j] 表示 s[i] 个字符后面是否有字符 'a'+j（即26个字母）
        // dp[i][j] 等于 s.length() 时表示没有，否则表示有
        int n = s.length();
        int[][] dp = new int[n + 1][26];
        Arrays.fill(dp[n], n); //给多出的一行赋最大值，表示后面没有任何字符了

        // 开始预处理
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (s.charAt(i) == (char) ('a' + j))
                    dp[i][j] = i;
                else
                    dp[i][j] = dp[i + 1][j];
            }
        }

        // 开始判断
        String ret = "";
        for (String word : dictionary) {
            if (word.length() < ret.length() || (word.length() == ret.length() && word.compareTo(ret) > 0))
                continue;

            boolean isContinue = true;
            int i = 0;
            for (int j = 0; j < word.length(); j++) {
                if (dp[i][word.charAt(j) - 'a'] == n) {
                    isContinue = false;
                    break;
                }
                i = dp[i][word.charAt(j) - 'a'] + 1;
            }

            if (!isContinue)
                continue;

            // 当新符合条件的字符串长度大于旧的时，或者长度等于并且字典序在旧的字符串前面时才新赋值
            ret = word;
        }

        return ret;
    }

    public static void main(String[] args) {
        String s1 = "abpcplea";
        List<String> arr1 = new ArrayList<>(Arrays.asList("ale", "apple", "money", "plea"));
        System.out.println(findLongestWord(s1, arr1));

        String s2 = "abpcplea";
        List<String> arr2 = new ArrayList<>(Arrays.asList("a", "b", "c", "d"));
        System.out.println(findLongestWord(s2, arr2));

        String s3 = "dreaming";
        List<String> arr3 = new ArrayList<>(Arrays.asList("aeal", "dreamin", "ddddd", "dreaming"));
        System.out.println(findLongestWord(s3, arr3));

        String s4 = "abce";
        List<String> arr4 = new ArrayList<>(Arrays.asList("abc", "abe"));
        System.out.println(findLongestWord(s4, arr4));
    }
}
