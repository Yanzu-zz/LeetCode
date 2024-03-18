class NumArray:

  def __init__(self, nums: List[int]):
    n = len(nums)
    self.preNums = [0] * (n+1)
    for i in range(1, n+1):
      self.preNums[i] = self.preNums[i-1] + nums[i - 1]

  def sumRange(self, left: int, right: int) -> int:
    return self.preNums[right + 1] - self.preNums[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
