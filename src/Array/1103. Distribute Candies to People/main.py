class Solution:
  def distributeCandies(self, candies: int, num_people: int) -> List[int]:
    ans = [0] * num_people
    curCandi = 1
    i = -1

    while candies > 0:
      ans[(i+1) % num_people] += min(candies, curCandi)
      i += 1
      candies -= curCandi
      curCandi += 1

    return ans
