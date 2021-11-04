import java.util.Arrays;

class Solution238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int left = 1, right = 1; // 分别代表左右的乘积
        int[] products = new int[n];
        Arrays.fill(products, 1);

        // 最终每个元素其左右乘积进行相乘得出结果
        for (int i = 0; i < n; i++) {
            products[i] *= left;
            left *= nums[i];

            products[n - i - 1] *= right;
            right *= nums[n - i - 1];
        }

        return products;
    }
}