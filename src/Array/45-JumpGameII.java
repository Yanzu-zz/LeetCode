package Array;

class Solution45 {
    public static int jump(int[] nums) {
        int len = nums.length;
        int end = 0, maxPosition = 0, steps = 0;

        for (int i = 0; i < len - 1; i++) {
            // 找到下一跳最大的值
            maxPosition = Math.max(maxPosition, i + nums[i]);
            if (i == end) { // 到达上次跳跃能到达的右边界
                end = maxPosition; //目前能跳到的最远位置变成了下次起跳位置的有边界
                steps++;
            }
        }

        return steps;
    }

    public static void main(String[] args) {
        int[] arr1 = {2, 3, 1, 1, 4};
        int m1 = jump(arr1);
        System.out.println(m1);
        System.out.println();

        int[] arr2 = {2, 3, 0, 1, 4};
        int m2 = jump(arr2);
        System.out.println(m2);
        System.out.println();

        int[] arr3 = {1, 2, 3, 1, 4, 1, 1, 1, 5};
        int m3 = jump(arr3);
        System.out.println(m3);
        System.out.println();

        int[] arr4 = {1, 2, 3, 4, 5};
        int m4 = jump(arr4);
        System.out.println(m4);
        System.out.println();

        int[] arr5 = {2, 3, 1};
        int m5 = jump(arr5);
        System.out.println(m5);
        System.out.println();

        int[] arr6 = {1, 2};
        int m6 = jump(arr6);
        System.out.println(m6);
        System.out.println();

        int[] arr7 = {1, 2, 1, 1, 1};
        int m7 = jump(arr7);
        System.out.println(m7);
        System.out.println();

        int[] arr8 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};
        int m8 = jump(arr8);
        System.out.println(m8);
        System.out.println();
    }
}