import java.util.*;
class Solution {
    int n;
    int[][] grid;
    int[] d = {0, 1, 0, -1, 0};
    public int largestIsland(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        int id = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, id);
                    map.put(id, size);
                    id++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int size = 1;
                    HashSet<Integer> set = new HashSet<>();
                    for (int k = 0; k < 4; k++) {
                        int r = i + d[k];
                        int c = j + d[k + 1];
                        if (r >= 0 && r < n &&
                            c >= 0 && c < n &&
                            grid[r][c] > 1) {
                            int x = grid[r][c];
                            if (set.add(x)) {
                                size += map.get(x);
                            }
                        }
                    }
                    ans = Math.max(ans, size);
                }
            }
        }
        if (ans == 0)
            return n * n;
        return ans;
    }
    int dfs(int i, int j, int id) {
        if (i < 0 || i >= n ||
            j < 0 || j >= n ||
            grid[i][j] != 1)
            return 0;
        grid[i][j] = id;
        int size = 1;
        for (int k = 0; k < 4; k++) {
            size += dfs(i + d[k], j + d[k + 1], id);
        }
        return size;
    }
}