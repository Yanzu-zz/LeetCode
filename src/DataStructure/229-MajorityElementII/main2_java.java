import java.util.*;

class Solution229 {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        List<Integer> res = new ArrayList<>();

        // 初始化两个候选人candidate，和他们的计票
        int cand1 = nums[0], count1 = 0;
        int cand2 = nums[0], count2 = 0;

        // 摩尔投票法，分为两个阶段：配对阶段和计数阶段
        // 配对阶段
        for (int num : nums) {
            // 值是候选人的一个的时候
            if (num == cand1) {
                count1++;
                continue;
            } else if (num == cand2) {
                count2++;
                continue;
            }

            // 当前候选人的值耗尽，需要换人
            if (count1 == 0) {
                cand1 = num;
                count1++;
                continue;
            } else if (count2 == 0) {
                cand2 = num;
                count2++;
                continue;
            }

            // 值不是候选人的时候，两个的票都减一
            count1--;
            count2--;
        }

        // 计数阶段
        // 因为不可能有3个候选人都超过 N/3
        // 找到了两个候选人之后，需要确定票数是否满足大于 N/3
        int majority = n / 3;
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == cand1)
                count1++;
            else if (cand2 == num)
                count2++;
        }
        if (count1 > majority)
            res.add(cand1);
        if (count2 > majority)
            res.add(cand2);

        return res;
    }
}