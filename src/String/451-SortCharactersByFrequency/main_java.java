import java.util.*;

class Solution451 {
    public static String frequencySort(String s) {
        // 统计词频
        Map<Character, Integer> map = new HashMap<>();
        int n = s.length();

        int i, j;
        for (i = 0; i < n; i++) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // 给哈希表排序
        List<Character> list = new ArrayList<Character>(map.keySet());
        Collections.sort(list, (a, b) -> map.get(b) - map.get(a));

        // 接下来就逐个填充即可
        StringBuffer sb = new StringBuffer();
        int size = list.size();
        for (i = 0; i < size; i++) {
            char c = list.get(i);
            int frequency = map.get(c);
            for (j = 0; j < frequency; j++)
                sb.append(c);
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(frequencySort("tree"));
    }
}