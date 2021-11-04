import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution312 {
    public int maxCoins(int[] nums) {
        int ans = 0;
        List<Integer> balloons = new ArrayList<>();
        for (int num : nums) balloons.add(num);

        while (balloons.size() > 0) {
            int minVal = Integer.MAX_VALUE, minIdx = 0;
            // 寻找最小值及其索引
            int i = 0;
            for (; i < balloons.size(); i++) {
                if (balloons.get(i) < minVal) {
                    minVal = balloons.get(i);
                    minIdx = i;
                }
            }

            // 引爆气球获取得分
            int leftVal = 1, rightVal = 1; // 左右边的得分
            if (minIdx > 0)
                leftVal = balloons.get(minIdx - 1);
            if (minIdx < balloons.size() - 1)
                rightVal = balloons.get(minIdx + 1);
            // 计算本次得分
            ans += leftVal * balloons.get(minIdx) * rightVal;

            // 移除本次最小值
            balloons.remove(minIdx);
        }

        return ans;
    }
}