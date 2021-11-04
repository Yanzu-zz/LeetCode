import java.util.Arrays;
import java.util.TreeSet;

class Solution414_3 {
    public int thirdMax(int[] nums) {
        int n = nums.length;
        long a = Long.MIN_VALUE, b = Long.MIN_VALUE, c = Long.MIN_VALUE;

        for (int num : nums) {
            if (num > a) {
                c = b;
                b = a;
                a = num;
            } else if (num < a && num > b) {
                c = b;
                b = num;
            } else if (num < b && num > c) {
                c = num;
            }
        }

        return c == Long.MIN_VALUE ? (int) a : (int) c;
    }
}