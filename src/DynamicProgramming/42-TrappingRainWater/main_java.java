class Solution42 {
    public int trap(int[] height) {
        int n = height.length;
        if (n == 0) // 特判防止没元素而取了第一个元素导致异常
            return 0;

        int ret = 0;
        int[] leftMax = new int[n],
                rightMax = new int[n];

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMax[i] = Math.max(leftMax[i - 1], height[i]);

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = Math.max(rightMax[i + 1], height[i]);

        for (int i = 0; i < n; i++)
            ret += Math.min(leftMax[i], rightMax[i]) - height[i];

        return ret;
    }
}