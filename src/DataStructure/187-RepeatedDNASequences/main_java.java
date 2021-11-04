import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution187 {
    private final static int L = 10; // 滑动窗口大小

    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();
        List<String> ret = new ArrayList<String>();
        Map<String, Integer> map = new HashMap<String, Integer>();

        // 要是 s 长度不超过11，就不会执行下面的循环，直接返回空数组
        for (int i = 0; i <= n - L; i++) {
            String tmp_substr = s.substring(i, i + L); // 截取每次都以 s[i] 开头且长度为 L=10 的子串
            map.put(tmp_substr, map.getOrDefault(tmp_substr, 0) + 1); // 然后加进我们的哈希表中，若是新的子串，则默认值为1，否则为之前的次数+1
            // 当一个子串出现的次数超过2之后，就是我们要找的子串，此时我们把它加进待返回的数组中即可
            if (map.get(tmp_substr) == 2)
                ret.add(tmp_substr);
        }

        return ret;
    }
}