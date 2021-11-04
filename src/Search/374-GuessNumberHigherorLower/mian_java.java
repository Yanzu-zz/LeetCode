/**
 * Forward declaration of guess API.
 *
 * @param num your guess
 * @return -1 if num is lower than the guess number
 * 1 if num is higher than the guess number
 * otherwise return 0
 * int guess(int num);
 */

/**
 * 解决方法一：二分查找
 *  和278题思路一致，边界条件注意一下即可
class Solution374 {
    public int guessNumber(int n) {
        int i = 1, j = n;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (guess(mid) > 0)
                i = mid + 1;
            else if (guess(mid) < 0)
                j = mid;
            else
                return mid;
        }

        return i;
    }
}
 */
