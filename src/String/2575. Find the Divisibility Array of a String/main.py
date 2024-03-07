from typing import List


class Solution:
  def divisibilityArray(self, word: str, m: int) -> List[int]:
    n = len(word)
    ans = [0] * n
    curNum = 0

    for i in range(0, n):
      curNum = (curNum * 10 + int(word[i])) % m
      if curNum % m == 0:
        ans[i] = 1

    return ans


print(Solution().divisibilityArray("998244353", 3))
