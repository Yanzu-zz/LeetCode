class Solution:
    def splitNum(self, num: int) -> int:
        cnt = [0] * 10
        while num > 0:
            cnt[int(num % 10)] += 1
            num /= 10

        # 交替添加小的数值
        flag = True
        a, b = 0, 0
        for i in range(1, 10):
            while cnt[i] != 0:
                if flag:
                    a = a * 10 + i
                else:
                    b = b * 10 + i
                flag = not flag
                cnt[i] -= 1

        return a + b
