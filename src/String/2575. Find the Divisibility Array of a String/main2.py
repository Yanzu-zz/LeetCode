class Solution:
  def divisibilityArray(self, word: str, m: int) -> List[int]:
    n = len(word)
    ans = [0] * n
    curNum = 0

    for i, d in enumerate(map(int, word)):
      curNum = (curNum * 10 + d) % m
      ans[i] = 1 if curNum % m == 0 else 0

    return ans
