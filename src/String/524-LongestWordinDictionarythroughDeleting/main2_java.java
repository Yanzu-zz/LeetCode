import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution524_2 {
    public static String findLongestWord(String s, List<String> dictionary) {
        String ret = "";
        for (String t : dictionary) {
            int i = 0, j = 0;
            while (i < t.length() && j < s.length()) {
                if (t.charAt(i) == s.charAt(j)) {
                    ++i;
                }
                ++j;
            }
            if (i == t.length()) {
                if (t.length() > ret.length() || (t.length() == ret.length() && t.compareTo(ret) < 0)) {
                    ret = t;
                }
            }
        }

        return ret;
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