class Solution238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] pre = new int[n], rear = new int[n];
        int[] products = new int[n];

        // 计算后缀积
        rear[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rear[i] = rear[i + 1] * nums[i];

        // 开始计算乘积，前缀积在这个时候一起计算
        pre[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            products[i] = pre[i - 1] * rear[i + 1];
            pre[i] = pre[i - 1] * nums[i];
        }
        // 前后两个因为边界问题要特判
        products[0] = rear[1];
        products[n - 1] = pre[n - 2];

        return products;
    }
}