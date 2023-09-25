class Solution:
    def bestTiming(self, prices: List[int]) -> int:
        maxProfit = 0
        minPrice = int(1e9)

        for price in prices:
            maxProfit = max(maxProfit, price - minPrice)
            minPrice = min(minPrice, price)

        return maxProfit
