class Solution162_2 {
    public static int findPeakElement(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) { // 此时峰值肯定是 mid 或 mid左边
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 1};
        System.out.println(findPeakElement(nums1));

        int[] nums2 = {1, 2, 1, 3, 5, 6, 4};
        System.out.println(findPeakElement(nums2));
    }
}