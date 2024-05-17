class Solution:
  def maxProfitAssignment(self, difficulty, profit, worker):
    def sort_d_p(difficulty, profit):
      combined = sorted(zip(difficulty, profit))
      d, p = zip(*combined)
      return list(d), list(p)

    # 排序
    d2, p2 = sort_d_p(difficulty, profit)
    worker.sort()

    n = len(difficulty)
    d_i = maxProfit = 0
    ans = 0
    for w in worker:
      # 确保有能力去干活
      while d_i < n and w >= d2[d_i]:
        maxProfit = max(maxProfit, p2[d_i])
        d_i += 1

      ans += maxProfit

    return ans


difficulty = [5, 50, 92, 21, 24, 70, 17, 63, 30, 53]
profit = [68, 100, 3, 99, 56, 43, 26, 93, 55, 25]
worker = [96, 3, 55, 30, 11, 58, 68, 36, 26, 1]
print(Solution().maxProfitAssignment(difficulty, profit, worker))
