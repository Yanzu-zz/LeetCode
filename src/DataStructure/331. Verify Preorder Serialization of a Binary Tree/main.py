class Solution:
  def isValidSerialization(self, preorder: str) -> bool:
    s = []

    for v in preorder.split(','):
      s.append(v)
      while len(s) >= 3 and s[-1] == s[-2] == '#' and s[-3] != '#':
        s.pop(), s.pop(), s.pop()
        s.append('#')

    return len(s) == 1 and s[0] == '#'
