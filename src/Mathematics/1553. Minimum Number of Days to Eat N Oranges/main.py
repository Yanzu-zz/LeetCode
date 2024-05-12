class Solution:
  def minDays(self, n: int) -> int:
    @cache
    def _m(n):
      if n <= 1:
        return n

      return min(_m(n // 2) + (n % 2), _m(n // 3) + (n % 3)) + 1

    return _m(n)
