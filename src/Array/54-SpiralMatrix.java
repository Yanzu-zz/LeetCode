package Array;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution54 {
    // 四个方向数组，顺序为：右下左上
    private static final int[][] orientation = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private static boolean[][] visited;
    private static int N, M;

    public static List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ret = new ArrayList<>();
        N = matrix.length;
        M = matrix[0].length;
        visited = new boolean[N][M];

        dfs(matrix, 0, 0, 0,  0, ret);

        return ret;
    }

    /**
     * 深搜解决顺时针遍历矩阵问题
     * @param matrix
     * @param step
     * @param x
     * @param y
     * @param stickOn  往哪个方向走到尽头，当越界时才向下一个方向改变
     * @param list
     */
    private static void dfs(int[][] matrix, int step, int x, int y, int stickOn, List<Integer> list) {
        if (step >= N * M)
            return;

        if (!visited[x][y]) {
            visited[x][y] = true;
            list.add(matrix[x][y]);
        }

        int newX, newY; // 下一个走的点
        newX = x + orientation[stickOn][0];
        newY = y + orientation[stickOn][1];
        if (!inMatrix(newX, newY) || visited[newX][newY]) {
            stickOn = (stickOn + 1) % orientation.length;
            newX = x + orientation[stickOn][0];
            newY = y + orientation[stickOn][1];
        }

        if (inMatrix(newX, newY) && !visited[newX][newY]) {
            dfs(matrix, step + 1, newX, newY, stickOn, list);
        }
    }

    private static boolean inMatrix(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    public static void main(String[] args) {
        int[][] arr1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        ArrayList<Integer> ret1 = (ArrayList<Integer>) spiralOrder(arr1);
        System.out.println(Collections.singletonList(ret1).toString());

        int[][] arr2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        ArrayList<Integer> ret2 = (ArrayList<Integer>) spiralOrder(arr2);
        System.out.println(Collections.singletonList(ret2).toString());

        int[][] arr3 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        ArrayList<Integer> ret3 = (ArrayList<Integer>) spiralOrder(arr3);
        System.out.println(Collections.singletonList(ret3).toString());
    }
}