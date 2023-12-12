from typing import List

from sortedcontainers import SortedList


class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1] * n

        # 把元素和索引绑定起来按照元素大小排序
        arr = [(x, i) for i, x in enumerate(nums)]
        arr.sort(key=lambda x: -x[0])

        # 下面开始寻找第二大元素
        # 用一个有序列表来决定当前元素的第二大值是哪个
        # 因为是有序且带有下标的，我们每次新加一个元素，就用它的下标寻找后面第二个索引就好
        s = SortedList()
        for x, i in arr:
            # j 就是比 x 后面第一个大的元素
            j = s.bisect_right(i)
            # 但我们需要找的是第二个大的元素，判断一下即可
            if j + 1 < len(s):
                ans[i] = nums[s[j + 1]]
            s.add(i)

        return ans
