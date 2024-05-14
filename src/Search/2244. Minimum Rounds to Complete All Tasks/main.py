from collections import Counter


class Solution:
  def minimumRounds(self, tasks: List[int]) -> int:
    counter = Counter(tasks)
    ans = 0

    # for num, cnt in counter.items():
    #   if cnt < 2:
    #     return -1
    #   ans += -(-cnt // 3)

    # return ans

    if 1 in counter.values():
      return -1

    # return sum((cnt + 2) // 3 for cnt in counter.values())
    return sum(-(-cnt // 3) for cnt in counter.values())
