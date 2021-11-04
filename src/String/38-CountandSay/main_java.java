class Solution38 {
    public String countAndSay(int n) {
        String prev = "1";
        for (int i = 2; i <= n; i++) { // 一轮一轮遍历模拟下去
            StringBuilder sb = new StringBuilder();
            int chStart = 0, curPos = 0; // 用来记录当前计算的字符是什么以及它的长度
            while (curPos < prev.length()) {
                // 遍历当前相同的字符
                while (curPos < prev.length() && prev.charAt(curPos) == prev.charAt(chStart))
                    curPos++;
                // 到这就表明当前相同的字符全部找到了，那我们加入字符串中
                sb.append(Integer.toString(curPos - chStart)).append(prev.charAt(chStart));
                chStart = curPos; // 将下个字符的开头位置更新
                // 重复这个动作，直至遍历完成，此时 i 这个数字的外观数列就完成了，进行下个数组的转化
            }
            prev = sb.toString();
        }

        return prev;
    }
}