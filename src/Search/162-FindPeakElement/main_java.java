class Solution162 {
    public int findPeakElement(int[] nums) {
        int maxVal = Integer.MIN_VALUE, maxIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }
}