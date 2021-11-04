import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution287 {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        Set<Integer> set = new HashSet<>();

        // 用哈希表就能轻易知道元素是否重复了
        for (int i = 0; i < n; i++) {
            if (set.contains(nums[i]))
                return nums[i];
            set.add(nums[i]);
        }

        return 0;
    }
}