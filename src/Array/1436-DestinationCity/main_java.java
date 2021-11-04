import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution1436 {
    public String destCity(List<List<String>> paths) {
        Set<String> citiesA = new HashSet<>();

        for (List<String> path : paths)
            citiesA.add(path.get(0));

        for (List<String> path : paths)
            if (!citiesA.contains(path.get(1)))
                return path.get(1);

        return "";
    }
}