import java.util.*;
class Solution {
    int[] parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void union(int a, int b) {
        a = find(a);
        b = find(b);
            if (a != b)
            parent[b] = a;
    }
    public int latestDayToCross(int row, int col, int[][] cells) {
        int n = row * col;
        int left = n;
        int right = n + 1;
        parent = new int[n + 2];
        for (int i = 0; i < n + 2; i++)
            parent[i] = i;
        int[][] grid = new int[row][col];
        int[] dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dc = {-1,  0,  1,-1, 1,-1, 0, 1};
        for (int day = 0; day < n; day++) {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            grid[r][c] = 1;
            int id = r * col + c;
            if (c == 0)
                union(id, left);
            if (c == col - 1)
                union(id, right);
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < row &&
                    nc >= 0 && nc < col &&
                    grid[nr][nc] == 1) {
                    int nid = nr * col + nc;
                    union(id, nid);
                }
            }
            if (find(left) == find(right))
                return day;
        }
        return 0;
    }
}