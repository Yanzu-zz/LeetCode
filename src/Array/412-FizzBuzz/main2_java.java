import java.util.ArrayList;
import java.util.List;

class Solution412 {
    public List<String> fizzBuzz(int n) {
        List<String> ret = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            StringBuilder sb = new StringBuilder(); // 用 stringbuild 加速字符串生成
            if (i % 3 == 0)
                sb.append("Fizz");
            if (i % 5 == 0)
                sb.append("Buzz");
            if (sb.length() == 0)
                sb.append(i);
            ret.add(sb.toString());
        }

        return ret;
    }
}