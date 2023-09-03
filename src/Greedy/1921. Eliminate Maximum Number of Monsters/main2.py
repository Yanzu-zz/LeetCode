class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
      # main.py 的快捷写法
      times = sorted((d - 1) // s for d, s in zip(dist, speed))

      for i, t in enumerate(times):
        if t < i:
          return i
      
      return len(times)
