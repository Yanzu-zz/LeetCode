from heapq import heappush, heapreplace


class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        # 根据 last_day 的先后来排名
        courses.sort(key=lambda c: c[1])
        # h 是堆，py 里面用函数即可让数组成堆
        h = []
        # 当前是第几天，某门课能上要求是当前天数小于last_day
        day = 0
        for duration, last_day in courses:
            if day + duration <= last_day:
                day += duration
                heappush(h, -duration)
            # 否则将上个消耗时间最长的课取消掉不上，上当前的这个
            # 当然，必须要保证之前上过课而且当前的课的消耗时间比之前最长的短
            # heapq 默认是最小堆，故我们时刻要记得加上负号让它变成最大堆
            elif h and duration < -h[0]:
                # 将当前的课消耗时长替换掉之前最长的课的消耗市场
                # 并且将时间差剪掉，注意这里 heapreplace 返回的是被替换的数值，我们存的是负数，需要反转
                day -= -heapreplace(h, -duration) - duration

        return len(h)
