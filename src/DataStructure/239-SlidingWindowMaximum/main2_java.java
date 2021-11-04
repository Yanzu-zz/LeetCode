import java.util.Comparator;
import java.util.Deque;
import java.util.LinkedList;
import java.util.PriorityQueue;

class MonotonicQueue {
    Deque<Integer> d;

    public MonotonicQueue() {
        d = new LinkedList<>(); // 双端队列
    }

    public void push(int n) {
        while (!d.isEmpty() && d.peekLast() < n)
            d.pollLast();
        d.addLast(n);
    }

    public int max() {
        return d.isEmpty() ? -1 : d.peekFirst();
    }

    public void pop(int n) {
        if (!d.isEmpty() && d.peekFirst() == n)
            d.pollFirst();
    }
}

class Solution239 {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ret = new int[n - k + 1];
        MonotonicQueue slideWindow = new MonotonicQueue();

        // 先填充满 k-1 个元素
        for (int i = 0; i < k - 1; i++)
            slideWindow.push(nums[i]);
        // 然后开始处理题目
        for (int i = k - 1; i < n; i++) {
            slideWindow.push(nums[i]);
            ret[i - k + 1] = slideWindow.max();
            slideWindow.pop(nums[i - k + 1]);
        }

        return ret;
    }
}