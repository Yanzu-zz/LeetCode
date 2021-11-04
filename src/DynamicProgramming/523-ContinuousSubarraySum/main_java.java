import java.util.HashSet;
import java.util.Set;

class Solution523 {
    public static boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        int[] preSums = new int[n + 1];
        Set<Integer> set = new HashSet<Integer>();

        // 计算前缀和
        int i;
        for (i = 0; i < n; i++)
            preSums[i + 1] = preSums[i] + nums[i];

        // 开始判断是否有同余
        for (i = 2; i <= n; i++) {
            set.add(preSums[i - 2] % k);
            if (set.contains(preSums[i] % k))
                return true;
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