import java.util.HashMap;
import java.util.Map;

/**
 * 方法一：回溯 + 记忆化搜索
 * 数组nums的每个元素都可以添加符号+或-，因此每个元素有2种添加符号的方法，n个数共有2n种添加符号的方法，对应20种不同的表达式。当n个元素都添加符号之后，即得到一种表达式，如果表达式的结果等于目标数target，则该表达式即为符合要求的表达式。
 * 可以使用回溯的方法遍历所有的表达式，回溯过程中维护一个计数器count，当遇到一种表达式的结果等于目标数target时，将count的值加1。遍历完所有的表达式之后，即可得到结果等于目标数target的表达式的数目。
 */
class Solution494_2 {
    private static int n, t;
    static Map<String, Integer> store = new HashMap<>();

    private static int dfs(int nums[], int step, int curVal) {
        String key = step + "_" + curVal;
        if (store.containsKey(key))
            return store.get(key);

        if (step == n) {
            store.put(key, curVal == t ? 1 : 0);
            return store.get(key);
        }

        int left = dfs(nums, step + 1, curVal + nums[step]);
        int right = dfs(nums, step + 1, curVal - nums[step]);

        store.put(key, left + right);
        return store.get(key);
    }

    public static int findTargetSumWays(int[] nums, int target) {
        n = nums.length;
        t = target;
        store.clear();
        return dfs(nums, 0, 0);
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 1, 1, 1, 1};
        int t1 = 3;
        System.out.println(findTargetSumWays(arr1, t1));

        int[] arr2 = {1};
        int t2 = 1;
        System.out.println(findTargetSumWays(arr2, t2));
    }
}