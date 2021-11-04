import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

/**
 * 解题思路一：DP
 * 由于题目没说数组是有序的，故我们需要先对数组进行排序
 * dp[i] 为到当前数字时最长整除子集的长度
 * 转移方程：dp[i] = dp[j] + 1  if nums[i] % nums[j] == 0 （因为只要 i能整除 j，则i就能整除 j 子集的所有元素）
 * 边界条件：dp[0] = 1
 * 得到最终结果后我们从最大的那个位置开始向前找子集，条件为 dp[j]==dp[i] - 1 && nums[i] % nums[j] == 0
 */
class Solution368 {
    public static List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length, maxVal = Integer.MIN_VALUE, maxIndex = 0;
        int i, j;
        int[] dp = new int[n];
        Arrays.fill(dp,1);

        // 题目没说数组是有序的，所以先给它排下序
        Arrays.sort(nums);

        // 开始 dp
        for (i = 1; i < n; i++) {
            for (j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0)
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            if (dp[i] >= maxVal) {
                maxVal = dp[i];
                maxIndex = i;
            }
        }

        // 从后往前寻找最长子集
        List<Integer> ret = new ArrayList<>();
        i = maxIndex;
        ret.add(0,nums[i]);
        while (i >= 0) {
            for (j = i - 1; j >= 0; j--) {
                if (dp[j] == dp[i] - 1 && nums[i] % nums[j] == 0 && !ret.contains(nums[j])) {
                    ret.add(0, nums[j]);
                    i = j;
                    break;
                }
            }
            i=j;
        }

        return ret;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3};
        int[] arr2 = {1, 2, 4, 8};
        int[] arr3 = {2, 3, 5, 7, 9};
        int[] arr4 = {1, 2, 4, 8, 9, 72};
        int[] arr5 = {1, 2, 3, 4, 6, 24};

        System.out.println(largestDivisibleSubset(arr1).toString());
        System.out.println(largestDivisibleSubset(arr2).toString());
        System.out.println(largestDivisibleSubset(arr3).toString());
        System.out.println(largestDivisibleSubset(arr4).toString());
        System.out.println(largestDivisibleSubset(arr5).toString());
    }
}