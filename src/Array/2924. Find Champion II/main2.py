class Solution:
  def findChampion(self, n: int, edges: List[List[int]]) -> int:
    isChampion = [True] * n
    for a, b in edges:
      isChampion[b] = False

    res = -1
    for i, val in enumerate(isChampion):
      if isChampion[i]:
        if res != -1:
          return -1

        res = i

    return res
