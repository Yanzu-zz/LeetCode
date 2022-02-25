class Solution453 {
    public int minMoves(int[] nums) {
        int n = nums.length, minVal = Integer.MAX_VALUE, ans = 0;
        for (int num : nums) minVal = Math.min(minVal, num);

        for (int num : nums) ans += num - minVal;

        return ans;
    }
}