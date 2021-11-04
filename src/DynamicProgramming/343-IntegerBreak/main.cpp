#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution343 {
private:
    vector<int> memo;

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

    // 将 n 进行分割（至少分割两部分），使之可以获得最大乘积
    int breakInteger(int n) {
        if (n == 1)
            return 1;

        // 记忆化搜索
        if (memo[n] != -1)
            return memo[n];

        int res = -1;
        for (int i = 1; i <= n - 1; i++) {
            // 找到子问题的最优解
            // 注意，题目要求至少分割两部分哦
            // 对比 i*(n-i) 的原因是该数也可能是最大解之一
            res = max3(res, i * (n - i), i * breakInteger(n - i)); // i + (n-i)
        }

        memo[n] = res;
        return res;
    }

public:
    int integerBreak(int n) {
        assert(n >= 2);

        memo = vector<int>(n + 1, -1);
        return breakInteger(n);
    }
};

int main() {
    Solution343 *ret1 = new Solution343();
    cout << ret1->integerBreak(10) << endl;

    return 0;
}
