from collections import deque


class Solution:
  def finalString(self, s: str) -> str:
    q = deque()
    tail = False

    for ch in s:
      if ch == 'i':
        tail = not tail
      elif tail:
        q.append(ch)
      else:
        q.appendleft(ch)

    return ''.join(q if tail else reversed(q))
