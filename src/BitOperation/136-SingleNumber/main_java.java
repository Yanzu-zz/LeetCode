import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

class Solution136 {
    public int singleNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (!set.contains(nums[i])) // 无则添加
                set.add(nums[i]);
            else                        // 有则删除
                set.remove(nums[i]);
        }

        // 因为题目说了其余元素均会出现两次，故剩下的唯一一个就是要找的
        Iterator<Integer> it = set.iterator();
        if (it.hasNext())
            return it.next();

        return nums[0];
    }
}