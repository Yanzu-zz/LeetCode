import java.util.HashSet;
import java.util.Set;

class Solution3 {
    public static int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<Character>();
        int n = s.length();
        // 右窗口滑动指针，初始值为 -1，相当于在字符串左侧
        int right = -1, ret = 0;

        // 开始滚动
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                // 左指针向右移动一个，移除一个字符
                set.remove(s.charAt(i - 1));
            }
            while (right + 1 < n && !set.contains(s.charAt(right + 1))) {
                set.add(s.charAt(right + 1));
                right++;
            }
            // 更新每次得到的新的不重复字符串区间窗口的长度
            ret = Math.max(ret, right - i + 1);
        }

        return ret;
    }

    public static void main(String[] args) {
        String s1 = "abcabcbb";
        System.out.println(lengthOfLongestSubstring(s1));

        String s2 = "bbbbbb";
        System.out.println(lengthOfLongestSubstring(s2));

        String s3 = "pwwkew";
        System.out.println(lengthOfLongestSubstring(s3));
    }
}