class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        time %= (n - 1) << 1
        if time >= n - 1:
            time -= n - 1
            return n - time
        else:
            return time + 1
