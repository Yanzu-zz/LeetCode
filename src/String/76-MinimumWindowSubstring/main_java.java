class Solution76 {
    public String minWindow(String s, String t) {
        if (s == null || s.length() == 0 || t == null || t.length() == 0)
            return "";

        // count 是需求的字符个数
        int n = s.length(), count = t.length();
        int[] need = new int[128]; // 开多点空间，不额外判断大小写了
        for (int i = 0; i < count; i++)
            need[t.charAt(i)]++; // 记录需要的字符个数

        // l 是当前左边界，r是当前右边界
        int l = 0, r = 0;
        // size 记录窗口大小，start 是最小覆盖子串开始的索引位置
        int size = Integer.MAX_VALUE, start = 0;

        // 开始滑动遍历
        while (r < n) {
            char c = s.charAt(r);
            if (need[c] > 0) // 上面初始化了 t 子串里的字符，有的话数量是大于0的
                count--;
            need[c]--; // 把右边的字符加入窗口

            if (count == 0) { // 如果窗口中已经包含所有字符
                while (l < r && need[s.charAt(l)] < 0) {
                    need[s.charAt(l)]++; // 释放右边移动出窗口的字符
                    l++;
                }

                // 当前子串符合条件且更短时，就开始更新最小窗口长度
                if (r - l + 1 < size) {
                    size = r - l + 1;
                    start = l; // 记录此子串初始位置
                }

                // 重新开始下一轮循环
                need[s.charAt(l)]++;
                l++;
                count++;
            }
            r++;
        }

        return size == Integer.MAX_VALUE ? "" : s.substring(start, start + size);
    }
}