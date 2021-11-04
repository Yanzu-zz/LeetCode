class Solution405 {
    public String toHex(int num) {
        if (num == 0)
            return "0";

        StringBuffer sb = new StringBuffer();
        for (int i = 7; i >= 0; i--) {
            int val = (num >> (4 * i)) & 0xf; // 获得每个4位分组（4位二进制等于1位十六进制）

            // 因为有 32位 那么长，前面的分组大概率是0，而题目要求前面的0不能显示，所以就这么判断了
            // *只要判断到了一组不是0，就开始添加元素，而sb一旦有了长度，就会一直添加了 ^_^
            if (sb.length() > 0 || val > 0) {
                // 0-9的话正常返回，10-15 就处理一下
                char digit = val < 10 ? (char) ('0' + val) : (char) ('a' + val - 10);
                sb.append(digit);
            }
        }

        return sb.toString();
    }
}