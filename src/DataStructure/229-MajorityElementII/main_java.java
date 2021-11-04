import java.util.*;

class Solution229 {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();

        // 统计
        for (int num : nums) {
            if (!map.containsKey(num))
                map.put(num, 1);
            else
                map.put(num, map.get(num) + 1);
        }

        // 查看哪些值个数超过了 n/3
        int majority = n / 3;
        List<Integer> ans = new ArrayList<>();
        for (int x : map.keySet()) {
            if (map.get(x) > majority)
                ans.add(x);
        }


        return ans;
    }
}