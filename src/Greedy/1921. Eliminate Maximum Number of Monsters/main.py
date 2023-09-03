class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
      n=len(dist)
      times = [0] * n

      # times[i] = (dist[i]-1) / speed[i]
      for i in range(n):
        times[i] = (dist[i]-1) // speed[i]
      
      times.sort()
      ret = 0
      # 接着查看有多少个可以消灭
      for i in range(n):
        if times[i] < i:
          return i
      
      # 这里是全部都能消灭
      return n
