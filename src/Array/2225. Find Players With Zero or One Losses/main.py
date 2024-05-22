from collections import Counter


class Solution:
  def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
    # maxV = max(max(m) for m in matches)
    # winCnt = [0] * (maxV + 1)
    # loseCnt = [0] * (maxV + 1)

    # for m in matches:
    #   winCnt[m[0]] += 1
    #   loseCnt[m[1]] += 1

    # return [i for i in range(1, maxV+1) if winCnt[i] + loseCnt[i] > 0 and loseCnt[i] == 0], [i for i in range(1, maxV+1) if winCnt[i] + loseCnt[i] > 0 and loseCnt[i] == 1]
    player = set(x for m in matches for x in m)
    losser = Counter(b for a, b in matches)

    return [sorted(p for p in player if p not in losser)], sorted(p for p, c in losser.items() if c == 1)
