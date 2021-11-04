package Array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution56 {
    public static int[][] merge(int[][] intervals) {
        if (intervals.length == 0)
            return new int[0][2];

        // 以区间左端点进行排序
        Arrays.sort(intervals, (a, b) -> {
            return a[0] - b[0];
        });

        List<int[]> merged = new ArrayList<int[]>();
        merged.add(intervals[0]);
        int currentCompareIndex = 0;
        for (int i = 1; i < intervals.length; i++) {
            // 当最终合并数组为空时 或 下一个需要合并的数组的左端点比上一个数组的右端点还大时，就创建新的数组
            // 因为排过序，可以保证连续性
            if (merged.get(currentCompareIndex)[1] < intervals[i][0])
                merged.add(intervals[i]);
            else // 否则就比较新数组的右端点和上个数组右端点谁大
                merged.get(currentCompareIndex)[1] = Math.max(merged.get(currentCompareIndex)[1], intervals[i][1]);
            currentCompareIndex = merged.size() - 1;
        }

        return merged.toArray(new int[merged.size()][]);
    }

    public static void main(String[] args) {
        int[][] arr1 = {{1, 3}, {2, 6}, {8, 10}, {15, 16}};
        int[][] ret1 = merge(arr1);
        for (int i = 0; i < ret1.length; i++)
            System.out.print(Arrays.toString(ret1[i]));
        System.out.println();

        int[][] arr2 = {{1, 4}, {4, 5}};
        int[][] ret2 = merge(arr2);
        for (int i = 0; i < ret2.length; i++)
            System.out.print(Arrays.toString(ret2[i]));
    }
}
