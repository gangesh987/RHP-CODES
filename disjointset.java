import java.util.*;
public class disjointset {
    static int[] parent;
    static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    static void join(int a, int b) {
        int left = find(a);
        int right = find(b);
        if (left != right) {
            parent[right] = left;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            join(a, b);
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (find(i) == i)
                count++;
        }
        System.out.println(count);
    }
}