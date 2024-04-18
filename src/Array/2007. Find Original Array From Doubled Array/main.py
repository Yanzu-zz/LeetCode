from collections import Counter


class Solution:
  def findOriginalArray(self, changed: List[int]) -> List[int]:
    changed.sort()
    cnt = Counter()
    ans = []

    for x in changed:
      # 标记一下 2*x 元素（这里不管原数组有没有）
      if x not in cnt:
        cnt[x * 2] += 1
        ans.append(x)
      else:
        # 然后，遇到了 2*x 元素时候，就删除该标记，说明有配对的 2*x 元素
        # 当然，如果最后还有一些 2*x 元素没被删除，说明该数组不是双倍数组
        cnt[x] -= 1  # 注意这里的 x 是2*x
        if cnt[x] == 0:
          del cnt[x]

    return [] if cnt else ans
