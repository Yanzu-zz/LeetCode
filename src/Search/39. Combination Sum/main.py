class Solution:
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    ans = []

    @cache
    def dfs(i, t, arr):
      if i < 0:
        if t == 0:
          ans.append(list(arr))
        return

      # 如果此时剩余的 target 不够大，就往左走
      if candidates[i] > t:
        dfs(i-1, t, arr)
      else:
        # 选中当前的数字
        dfs(i, t-candidates[i], arr + (candidates[i],))
        # 不选当前位置
        dfs(i-1, t, arr)

    candidates.sort()
    dfs(len(candidates) - 1, target, ())
    return ans
