class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @cache
        def dfs(i, hold):
            # 到了第一天如果选择买入就减第一天的股票钱，否则就不干任何事
            if i < 0:
                return -prices[0] if hold else 0

            # 这一天是 持有股票 状态
            # 只能从 昨天也是持有股票而且昨天今天什么都不敢 和 昨天没有持有股票但到了今天买入了股票 两个状态转移过来
            if hold:
                return max(dfs(i - 1, 1), dfs(i - 1, 0) - prices[i])
            # 这一天是 没有持有股票 状态
            # 只能从 昨天没有持有股票 和 昨天持有股票但今天卖了股票 得来
            return max(dfs(i - 1, 0), dfs(i - 1, 1) + prices[i])

        return dfs(len(prices) - 1, 0)
