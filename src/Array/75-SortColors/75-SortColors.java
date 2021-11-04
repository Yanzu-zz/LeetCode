package a1;

import java.util.Arrays;

class Solution75 {
    public static void sortColors(int[] nums) {
        int[] cnt = new int[3]; // 计算三种颜色的个数，索引对应每种颜色
        for (int num : nums)
            cnt[num]++;

        // 覆盖元素 0
        for (int i = 0; i < cnt[0]; i++)
            nums[i] = 0;
        int oneEnd = cnt[0] + cnt[1];
        // 覆盖元素 1
        for (int i = cnt[0]; i < oneEnd; i++)
            nums[i] = 1;
        // 元素2
        for (int i = oneEnd; i < oneEnd + cnt[2]; i++)
            nums[i] = 2;
    }

    public static void main(String[] args) {
        int[] arr1 = {2, 0, 2, 1, 1, 0};
        sortColors(arr1);
        System.out.println(Arrays.toString(arr1));

        int[] arr2 = {0};
        sortColors(arr2);
        System.out.println(Arrays.toString(arr2));
    }
}