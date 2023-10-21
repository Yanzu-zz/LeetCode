class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        BULKY1 = 1e4
        BULKY2 = 1e9
        HEAVY = 100
        isBulky = False
        isHeavy = False
        ans = "Neither"

        volumn = length * width * height
        if length >= BULKY1 or width >= BULKY1 or height >= BULKY1 or volumn >= BULKY2:
            isBulky = True

        if mass >= HEAVY:
            isHeavy = True

        if isBulky and isHeavy:
            ans = "Both"
        elif isBulky and not isHeavy:
            ans = "Bulky"
        elif not isBulky and isHeavy:
            ans = "Heavy"

        return ans
