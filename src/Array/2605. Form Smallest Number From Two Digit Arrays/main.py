class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        cntA = [0] * 11
        cntB = [0] * 11
        n1 = len(nums1)
        n2 = len(nums2)
        a = nums1[0]
        b = nums2[0]

        for i in range(n1):
            cntA[nums1[i]] += 1
            a = min(a, nums1[i])

        for i in range(n2):
            cntB[nums2[i]] += 1
            b = min(b, nums2[i])

        # 找单个最小数字
        for i in range(1, 11):
            if cntA[i] != 0 and cntB[i] != 0:
                return i

        # 若没有最小数字，则用两边最小的拼在一起
        if (a < b):
            ret = a * 10 + b
        else:
            ret = b * 10 + a

        return ret
