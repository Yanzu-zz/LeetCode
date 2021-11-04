#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution343
{
private:
    vector<int> memo;

    int max3(int a, int b, int c)
    {
        return max(a, max(b, c));
    }

public:
    // 动态规划方法求解
    int integerBreak(int n)
    {
        assert(n >= 2);

        // memo[i] 表示将数字 i 分割（至少两部分）后得到的最大乘积
        vector<int> memo(n + 1, -1);
        memo[1] = 1;

        // 自底向上求解memo[i]
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i - 1; j++) // j + (i-j)
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);

        return memo[n];
    }
};

int main()
{
    Solution343 *ret1 = new Solution343();
    cout << ret1->integerBreak(10) << endl;

    return 0;
}
