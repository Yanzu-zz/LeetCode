package Array;

class Solution55 {
    public static boolean canJump(int[] nums) {
        int curIndex = 0;
        boolean isCanReach = true;

        if (nums.length == 1)
            return true;

        int nextStep = 0, nextMaxEleIndex;
        while (isCanReach && curIndex < nums.length - 1) {
            nextStep = curIndex + nums[curIndex];

            // 遇到 0 才有可能走不通
            if (nextStep < nums.length - 1 && nums[nextStep] == 0) {
                for (int i = Math.max(nums[curIndex] - 1, 0); i >= 0; i--) {
                    if (i == 0) {
                        isCanReach = false;
                        break;
                    }

                    // 一直找到不为 1 的值为止（因为前面就是0）
                    if (nums[curIndex + i] > 1) {
                        curIndex += i;
                        break;
                    }
                }
            } else
                curIndex += nums[curIndex];
        }

        return isCanReach;
    }

    public static void main(String[] args) {
        int[] arr1 = {2, 3, 1, 1, 4};
        boolean ret1 = canJump(arr1);
        System.out.println(ret1);

        int[] arr2 = {3, 2, 1, 0, 4};
        boolean ret2 = canJump(arr2);
        System.out.println(ret2);

        int[] arr3 = {0, 1};
        boolean ret3 = canJump(arr3);
        System.out.println(ret3);

        int[] arr4 = {0};
        boolean ret4 = canJump(arr4);
        System.out.println(ret4);

        int[] arr5 = {2, 0};
        boolean ret5 = canJump(arr5);
        System.out.println(ret5);
    }
}
