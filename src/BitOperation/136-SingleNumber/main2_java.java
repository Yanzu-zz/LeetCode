import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

class Solution136_2 {
    public int singleNumber(int[] nums) {
        int ret = 0, n = nums.length;
        for (int num : nums)
            ret ^= num;

        return ret;
    }
}