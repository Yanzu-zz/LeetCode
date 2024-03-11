class Solution:
  def getHint(self, secret: str, guess: str) -> str:
    bulls = 0
    cows = 0
    cnt = [0] * 10
    n = len(secret)
    visited = [0] * n

    for i in range(n):
      if secret[i] == guess[i]:
        bulls += 1
        visited[i] = 1
      else:
        cnt[int(secret[i])] += 1

    for i in range(n):
      if visited[i] == 0 and cnt[int(guess[i])] > 0:
        cows += 1
        cnt[int(guess[i])] -= 1

    return "{}A{}B".format(str(bulls), str(cows))
