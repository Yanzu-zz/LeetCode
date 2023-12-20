class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        return "".join([word[0] for word in words]) == s
        # if len(words) != len(s):
        #     return False
        #
        # for i, word in enumerate(words):
        #     if word[0] != s[i]:
        #         return False
        #
        # return True
