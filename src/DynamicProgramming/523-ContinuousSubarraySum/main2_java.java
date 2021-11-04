import java.util.HashSet;
import java.util.Set;

class Solution523_2 {
    public static boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        int i, j, sum;
        for (i = 0; i < n - 1; i++)
            if (nums[i] == 0 && nums[i + 1] == 0)
                return true;


        for (i = 0; i < n; i++) {
            sum = nums[i];
            for (j = i + 1; j < n; j++) {
                sum += nums[j];
                if (sum % k == 0)
                    return true;
            }

            if (sum < k)
                break;
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr1 = {23, 2, 4, 6, 7};
        System.out.println(checkSubarraySum(arr1, 6));

        int[] arr2 = {23, 2, 6, 4, 7};
        System.out.println(checkSubarraySum(arr2, 6));
        System.out.println(checkSubarraySum(arr2, 13));
    }
}