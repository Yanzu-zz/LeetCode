# class Solution:
def countDigits(num: int) -> int:
    ans = 0
    tmp = num
    while tmp > 0:
        if num % (tmp % 10) == 0:
            ans += 1
        tmp = tmp // 10

    return ans


print(countDigits(121))
