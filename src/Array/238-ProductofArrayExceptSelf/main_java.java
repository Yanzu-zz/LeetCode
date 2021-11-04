class Solution238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] products = new int[n];

        for (int i = 0; i < n; i++) {
            int cur = 1; // 此轮的乘积
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;

                cur *= nums[j];
            }
            products[i] = cur;
        }

        return products;
    }
}