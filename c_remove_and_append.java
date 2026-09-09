import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] pos = new int[n + 1];
        for (int p = 1; p <= n; p++) {
            int curr = sc.nextInt();
            pos[curr] = p;
        }
        int next = n + 1;
        while (q-- > 0) {
            int val = sc.nextInt();
            pos[val] = next++;
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int val = 1; val <= n; val++)
            ans.add(val);
        ans.sort((a, b) -> pos[a] - pos[b]);
        for (int val : ans)
            System.out.print(val + " ");
    }
}