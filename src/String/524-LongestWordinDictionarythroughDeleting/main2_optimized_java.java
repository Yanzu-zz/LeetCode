import java.util.*;

// 根据 main2_java 的思路可知先按字符长度排序就不用判读这么多次了，找到第一个符合条件的直接返回即可
class Solution524_2_optimized {
    public static String findLongestWord(String s, List<String> dictionary) {
        // 把字典中所有元素按照长度排序（长→短）
        Collections.sort(dictionary, new Comparator<String>() {
            public int compare(String word1, String word2) {
                if (word1.length() != word2.length())
                    return word2.length() - word1.length();
                else
                    return word1.compareTo(word2);
            }
        });

        // 排完序从前往后找到第一个即是最长且字典序靠前的单词
        for (String t : dictionary) {
            int i = 0, j = 0;
            while (i < t.length() && j < s.length()) {
                if (t.charAt(i) == s.charAt(j)) {
                    ++i;
                }
                ++j;
            }
            if (i == t.length()) {
                return t;
            }
        }

        return "";
    }

    public static void main(String[] args) {
        String s1 = "abpcplea";
        List<String> arr1 = new ArrayList<>(Arrays.asList("ale", "apple", "money", "plea"));
        System.out.println(findLongestWord(s1, arr1));

        String s2 = "abpcplea";
        List<String> arr2 = new ArrayList<>(Arrays.asList("a", "b", "c", "d"));
        System.out.println(findLongestWord(s2, arr2));

        String s3 = "dreaming";
        List<String> arr3 = new ArrayList<>(Arrays.asList("aeal", "dreamin", "ddddd", "dreaming"));
        System.out.println(findLongestWord(s3, arr3));

        String s4 = "abce";
        List<String> arr4 = new ArrayList<>(Arrays.asList("abc", "abe"));
        System.out.println(findLongestWord(s4, arr4));
    }
}