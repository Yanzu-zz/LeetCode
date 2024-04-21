class Solution:
  def combinationSum3(self, k: int, n: int) -> List[List[int]]:
    ans = []

    num_arr = [i for i in range(1, 10)]

    @cache
    def dfs(i, t, arr):
      # boundary condition
      if i < 0 or len(arr) == k:
        if t == 0 and len(arr) == k:
          ans.append(list(arr))
        return

      # 不够大
      if num_arr[i] > t:
        dfs(i-1, t, arr)
      else:
        dfs(i-1, t-num_arr[i], arr + (num_arr[i],))
        dfs(i-1, t, arr)

    dfs(8, n, ())
    return ans
