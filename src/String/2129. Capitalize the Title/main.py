class Solution:
  def capitalizeTitle(self, title: str) -> str:
    ans = ""

    for word in title.split(" "):
      tmp1 = word.lower()

      if len(word) > 2:
        ans += word[0].upper() + tmp1[1]
      else:
        ans += tmp1

      ans += ' '

    return ans[:-1]
