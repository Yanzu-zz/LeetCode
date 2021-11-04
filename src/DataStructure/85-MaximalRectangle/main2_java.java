class Solution85 {
    public int largestRectangleArea(int[] heights) {
        // 特判和初始化
        int len = heights.length;
        if (len == 0)
            return 0;
        else if (len == 1)
            return heights[0];

        int res = 0;
        Deque<Integer> stack = new ArrayDeque<>(len); // 存的是下标，而不是元素本身
        // 开始往栈里添加元素
        for (int i = 0; i < len; i++) {
            // 从图里看到，一次添加有可能不知一个矩形的最大宽度可以被计算出来
            // 这个 while 是找到了比当前栈顶元素还小的元素时要做的事（这时这个小元素还没入栈）
            // 忘记了要干啥就看onenote笔记
            while (!stack.isEmpty() && heights[i] < heights[stack.peekLast()]) {
                int curHeight = heights[stack.pollLast()];
                // 有相同高度的就一直出栈
                while (!stack.isEmpty() && heights[stack.peekLast()] == curHeight)
                    stack.pollLast();

                // 下面就是计算当前出栈元素
                int curWidth;
                if (stack.isEmpty()) // 栈空了没啥好说的
                    curWidth = i;
                else // 栈不空的话从图中明显可以看出，此时的最大宽度为 小元素到当前元素 的距离
                    curWidth = i - stack.peekLast() - 1;

                res = Math.max(res, curWidth * curHeight);
            }
            stack.addLast(i); // 存的是下标
        }

        // 此时是入栈操作结束，有可能还有元素在里面（这时候里面的元素就是递增的了）
        while (!stack.isEmpty()) {
            // 下面的代码逻辑和上面的一样
            int curHeight = heights[stack.pollLast()];
            while (!stack.isEmpty() && heights[stack.peekLast()] == curHeight)
                stack.pollLast();

            int curWidth;
            if (stack.isEmpty())
                curWidth = len;
            else // 只不过这里的宽度是变成了总宽度来操作
                curWidth = len - stack.peekLast() - 1;

            res = Math.max(res, curWidth * curHeight);
        }

        return res;
    }

    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length;
        if (n == 0)
            return 0;

        int m = matrix[0].length;
        int[] height = new int[m];
        int maxArea = 0;

        // 确定以当前位置为底部的最高高度是多少
        for (char[] chars : matrix) {
            for (int j = 0; j < m; j++) {
                if (chars[j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            // 每层的最高高度确定后，就调用我们上节做过的求柱状图求最大矩形的单调栈解法
            maxArea = Math.max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
}