class Solution:
  def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
    # s[0] 是老板不生气时候的满意人数（100%满意，直接加起来就行）
    # s[1] 是老板生气时候的满意人数，这里是滑动数组，动态更新人数，最多人数用max_s1存储
    # 其实可以看到就是求 条件(grumpy[i] == 1)情况下的最大子数组
    s = [0, 0]
    max_s1 = -1
    n = len(customers)

    for i, (c, g) in enumerate(zip(customers, grumpy)):
      s[g] += c

      # 滑动窗口还没加满
      if i < minutes-1:
        continue

      max_s1 = max(max_s1, s[1])
      # 满了，此时要减去最左边加进来的元素，注意条件
      if grumpy[i-minutes+1]:
        s[1] -= customers[i-minutes+1]

    return s[0] + max_s1
