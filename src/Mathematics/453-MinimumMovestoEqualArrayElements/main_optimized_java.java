class Solution453 {
    public int minMoves(int[] nums) {
        int n = nums.length, minVal = Integer.MAX_VALUE, totalVal = 0;
        for (int num : nums) {
            totalVal += num;
            minVal = Math.min(minVal, num);
        }

        return totalVal - minVal * n;
    }
}