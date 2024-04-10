class Solution:
  def maximumBinaryString(self, binary: str) -> str:
    # 找到第一个 0
    i = binary.find('0')
    # 如果全是 1
    if i < 0:
      return binary

    cnt1 = binary.count('1', i)
    return '1' * (len(binary) - cnt1 - 1) + '0' + '1' * cnt1
