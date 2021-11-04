import java.util.HashMap;
import java.util.Map;

class Solution525 {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (nums[i - 1] == 1 ? 1 : -1);
        int ans = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);
        for (int i = 2; i <= n; i++) {
            if (!map.containsKey(sum[i - 2])) map.put(sum[i - 2], i - 2);
            if (map.containsKey(sum[i])) ans = Math.max(ans, i - map.get(sum[i]));
        }
        return ans;
    }
}