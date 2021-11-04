import java.util.Arrays;
import java.util.TreeSet;

class Solution414_2 {
    public int thirdMax(int[] nums) {
        TreeSet<Integer> treeSet = new TreeSet<Integer>();
        int n = nums.length;
        for (int num : nums) {
            treeSet.add(num); // 添加元素时会自动上浮下沉保持大小顺序
            if (treeSet.size() > 3) // 我们只需要控制它的窗口大小为3即可
                treeSet.remove(treeSet.first());
        }

        return treeSet.size() == 3 ? treeSet.first() : treeSet.last();
    }
}