import java.util.Comparator;
import java.util.PriorityQueue;

class Solution239 {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        // 创建大根堆（优先队列）
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return o1[0] != o2[0] ? o2[0] - o1[0] : o2[1] - o1[1];
            }
        });

        // 首先将窗口长度的值加进队列中
        for (int i = 0; i < k; i++)
            pq.offer(new int[]{nums[i], i});

        int[] ret = new int[n - k + 1];
        ret[0] = pq.peek()[0];
        for (int i = k; i < n; i++) {
            pq.offer(new int[]{nums[i], i}); // 加入新元素
            // 查看当前堆顶元素是否越界（其余小元素就算越界了也不用理，我们只关心大的）
            while (pq.peek()[1] <= i - k)
                pq.poll();

            ret[i - k + 1] = pq.peek()[0];
        }

        return ret;
    }
}