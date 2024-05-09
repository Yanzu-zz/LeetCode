class Solution:
  def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
    n = len(plants)
    a_i, b_i = 0, n-1
    a_cur, b_cur = capacityA, capacityB
    ans = 0

    while a_i < b_i:
      # A 不够水了，需要装满
      if a_cur < plants[a_i]:
        a_cur = capacityA
        ans += 1
      a_cur -= plants[a_i]

      # B 不够水
      if b_cur < plants[b_i]:
        b_cur = capacityB
        ans += 1
      b_cur -= plants[b_i]

      a_i += 1
      b_i -= 1

    # 中间的情况
    if n % 2 == 1:
      if max(a_cur, b_cur) < plants[a_i]:
        ans += 1

    return ans
