class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        s = set()
        sunnyIdx = []
        last = -1
        ans = [1] * len(rains)

        for i, rain in enumerate(rains):
            if rain == 0:
                sunnyIdx.append(i)
                last = rain
                continue

            if rain == last:
                return []

            if rain in s:
                if len(sunnyIdx) <= 0:
                    return []
                ans[sunnyIdx.pop(-1)] = rain
                ans[i] = -1
            else:
                ans[i] = -1
                s.add(rain)
            last = rain

        return ans
