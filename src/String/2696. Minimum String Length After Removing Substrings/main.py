class Solution:
    def minLength(self, text: str) -> int:
        s = []

        for ch in text:
            s.append(ch)

            if len(s) >= 2:
                # 两种要出栈的情况
                if (s[-1] == 'B' and s[-2] == 'A') or (s[-1] == 'D' and s[-2] == 'C'):
                    s.pop()
                    s.pop()

        return len(s)
