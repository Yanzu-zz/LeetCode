import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution525_2 {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (nums[i - 1] == 1 ? 1 : -1);
        int ans = 0;
        int[] hash = new int[2 * n + 1];
        Arrays.fill(hash, -1);
        hash[0 + n] = 0;
        for (int i = 2; i <= n; i++) {
            if (hash[sum[i - 2] + n] == -1) hash[sum[i - 2] + n] = i - 2;
            if (hash[sum[i] + n] != -1) ans = Math.max(ans, i - hash[sum[i] + n]);
        }
        return ans;
    }
}