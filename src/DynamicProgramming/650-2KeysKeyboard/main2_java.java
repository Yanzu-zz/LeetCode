class Solution650_2 {
    private static int minStep(int n) {
        if (n == 1)
            return 0;

        for (int i = 2; i < n / 2; i++) {
            if (n % i == 0)
                return i + minSteps(n / i);
        }

        return n;
    }

    public static int minSteps(int n) {
        // 不考虑存储前面的结果的话直接递归就行
        return minStep(n);
    }

    public static void main(String[] args) {
        for (int i = 1; i <= 12; i++)
            System.out.println(minSteps(i));
    }
}