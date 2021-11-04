import java.util.Stack;

class Solution32 {
    public int longestValidParentheses(String s) {
        Stack<Integer> stk = new Stack<>();
        int n = s.length(), ret = 0;

        int currLen = 0;
        for (int i = 0, start = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                stk.push(i);
            } else {
                if (!stk.empty()) {
                    stk.pop();    //匹配成功
                    if (stk.empty()) ret = Math.max(ret, i - start + 1);
                    else ret = Math.max(ret, i - stk.peek()); //i - st.top() + 1 - 1
                } else start = i + 1;  //更新起点
            }
        }
        return ret;
    }
}