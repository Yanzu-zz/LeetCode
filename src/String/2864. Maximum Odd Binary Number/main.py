class Solution:
  def maximumOddBinaryNumber(self, s: str) -> str:
    # oneCnt = sum([1 if ch == '1' else 0 for ch in s])
    oneCnt = s.count('1')
    return '1' * (oneCnt - 1) + '0' * (len(s) - oneCnt) + '1'