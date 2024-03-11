class Solution:
  def getHint(self, secret: str, guess: str) -> str:
    bulls = 0
    cows = 0
    cnt1 = [0] * 10
    cnt2 = [0] * 10
    n = len(secret)

    for i in range(n):
      if secret[i] == guess[i]:
        bulls += 1
      else:
        cnt1[int(secret[i])] += 1
        cnt2[int(guess[i])] += 1

    for i in range(10):
      cows += min(cnt1[i], cnt2[i])

    # return "{}A{}B".format(str(bulls), str(cows))
    return f"{bulls}A{cows}B"
