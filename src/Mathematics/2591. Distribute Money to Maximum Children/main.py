class Solution:
    def distMoney(self, money: int, children: int) -> int:
        # 特判
        # 不可能情况
        if money < children:
            return -1
        # 如果总钱数 > 孩子数量8倍，则除了剩下的那个其它全给 8 美刀
        if money > children << 3:
            return children - 1
        # 额特判例子，自己理解下
        if money == (children << 3) - 4:
            return children - 2

        # 1. 先分给每个儿童1美元（也就是 money-children）
        # 2. 然后就是每个人再分7美刀，看看能给多少个
        return (money - children) // 7
