/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

/**
 * 解决方法一：二分查找法
 * 用二分查找的思路寻找第一个 bad version，只不过判断条件有变：
 * i = mid + 1 if isBadVersion(i) == false
 * j = mid - 1 if isBadVersion(i) == true
class Solution278_3  {
    public int firstBadVersion(int n) {
        if(isBadVersion(n-1))
            return n;

        int i = 1, j = n;
        int mid = i + (j - i) / 2;
        while (i < j) {
            mid = i + (j - i) / 2;
            if (isBadVersion(mid))
                j = mid;
            else
                i = mid + 1;
        }

        return mid;
    }
}
 */
