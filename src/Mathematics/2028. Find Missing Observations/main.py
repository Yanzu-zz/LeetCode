class Solution:
  def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
    remainingV = (len(rolls) + n) * mean - sum(rolls)
    if not n <= remainingV <= 6*n:
      return []

    avg, extra = divmod(remainingV, n)
    return [avg + 1] * extra + [avg] * (n-extra)
