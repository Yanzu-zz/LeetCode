class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        x, y = (tomatoSlices - 2 * cheeseSlices) // 2, (4 * cheeseSlices - tomatoSlices) // 2
        if x < 0 or y < 0 or x * 2 != tomatoSlices - 2 * cheeseSlices:
            return []

        return [x, y]
