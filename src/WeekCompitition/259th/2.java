class Solution2 {
    public int sumOfBeauties(int[] nums) {
        int n = nums.length;

        // 从后往前预存储当前位置后面的最大值
        int[] preBack = new int[n];
        preBack[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            preBack[i] = Math.min(nums[i], preBack[i + 1]);

        // 从前往后存储当前位置前面的最大值
        int[] preFront = new int[n];
        preFront[0] = nums[0];
        for (int i = 1; i < n; i++)
            preFront[i] = Math.max(nums[i], preFront[i - 1]);

        // 开始求美丽值
        int beautyNum = 0;
        for (int i = 1; i <= n - 2; i++) {
            if (nums[i] > preFront[i - 1] && nums[i] < preBack[i + 1])
                beautyNum += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                beautyNum += 1;
        }

        return beautyNum;
    }
}