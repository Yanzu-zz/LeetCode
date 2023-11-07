class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        vowels = ['a', 'e', 'i', 'o', 'u']
        return sum(1 for i in range(left,right+1) if words[i][0] in vowels and words[i][-1] in vowels)
        # ans = 0
        # for word in words[left:right + 1]:
        #     if word[0] in vowels and word[-1] in vowels:
        #         ans += 1
        # return ans
