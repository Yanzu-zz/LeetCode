class Solution:
  def numberOfWeeks(self, milestones):
    # maxV = max(milestones)
    # sumV = sum(milestones)

    # return (sumV - maxV) * 2 + 1 if maxV > sumV - maxV + 1 else sumV
    maxV = max(milestones)
    remainingV = sum(milestones) - maxV
    gap = maxV - remainingV

    return remainingV * 2 + 1 if gap > 0 else maxV + remainingV


print(Solution().numberOfWeeks([1, 2, 3]))
