class Solution:
  def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
    # mainTank - 5 ==> mainTank - 5 + 1 ==> mainTakn - 4
    return (mainTank + min((mainTank-1)//4, additionalTank)) * 10
