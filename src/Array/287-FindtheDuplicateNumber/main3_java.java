import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution287 {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int cnt = 0;
            for (int num : nums) {
                if (num <= mid)
                    cnt++;
            }

            if (cnt > mid)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}