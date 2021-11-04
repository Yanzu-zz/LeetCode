import java.util.HashSet;
import java.util.Set;

class Solution128 {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        if (n == 0 || n == 1)
            return n;

        int ret = 1;
        Set<Integer> set = new HashSet<>();
        for (int num : nums) // 初始化set
            set.add(num);

        for (int i = 0; i < n; i++) {
            if (!set.contains(nums[i] - 1)) { // 如果包含比它更小的连续数组，则不计算这个位置
                int curVal = nums[i] + 1, curMaxLen = 1;
                while (set.contains(curVal)) {
                    curMaxLen++; // 最大长度+1
                    curVal++;    // 查询下个连续元素
                }

                ret = Math.max(ret, curMaxLen);
            }
        }

        return ret;
    }
}