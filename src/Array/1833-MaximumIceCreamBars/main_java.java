import java.util.Arrays;

class Solution1833 {
    public static int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int n = costs.length;

        int i = 0, remainings = coins, count = 0;
        for (; i < n; i++) {
            remainings -= costs[i];
            if (remainings >= 0)
                count++;
            else
                break;
        }

        return count;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 3, 2, 4, 1};
        int coins1 = 7;
        System.out.println(maxIceCream(arr1, coins1));

        int[] arr2 = {10, 6, 8, 7, 7, 8};
        int coins2 = 5;
        System.out.println(maxIceCream(arr2, coins2));
    }
}