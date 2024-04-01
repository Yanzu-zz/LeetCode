class Solution:
  def finalString(self, s: str) -> str:
    n = len(s)
    ans = ''

    for i in range(n):
      # 遇到 i 反转前面的
      if s[i] == 'i':
        ans = ans[::-1]
      else:
        ans += s[i]

    # return ''.join([ch if ch != 'i' else '' for ch in ans])
    return ans
