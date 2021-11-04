import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution524 {
    public static String findLongestWord(String s, List<String> dictionary) {
        char a, b;
        int i, j;
        int dicNum = Integer.MAX_VALUE; // 字典序，用来比较相同长度的字符串
        String ret = "";
        int longestStrLen = Integer.MIN_VALUE;

        for (String word : dictionary) {
            // 比当前获取到最长长度单词更长才继续比较
            if (word.length() < longestStrLen)
                continue;

            a = s.charAt(0);
            b = word.charAt(0);

            i = s.indexOf(b);
            if(i!=-1){
            }

            for (i = 0, j = 0; i < s.length();) {
                if (a == b && j != word.length() - 1) {
                    i++;
                    j++;
                    a = s.charAt(i);
                    b = word.charAt(j);
                } else if (a == b && j == word.length() - 1) {
                    break;
                } else {
                    i++;
                    a = s.charAt(i);
                }
            }

            if (j == word.length() - 1) {
                if (word.length() == longestStrLen) {
                    if (i < dicNum) {
                        dicNum = i - 1;
                        ret = word;
                        longestStrLen = word.length();
                    }
                } else {
                    ret = word;
                    longestStrLen = word.length();
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
