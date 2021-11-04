import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution187_2 {
    private final static int L = 10; // 滑动窗口大小
    private final static int N = (int) 1e5 + 10, P = 131313;

    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();
        int[] h = new int[N], p = new int[N];
        List<String> ret = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();

        // 初始化哈希值
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * P + s.charAt(i - 1);
            p[i] = p[i - 1] * P;
        }

        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            int hash = h[j] - h[i - 1] * p[j - i + 1];
            int cnt = map.getOrDefault(hash, 0);
            if (cnt == 1)
                ret.add(s.substring(i - 1, i + L - 1));
            map.put(hash, cnt + 1);
        }

        return ret;
    }
}