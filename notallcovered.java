import java.util.*;
public class notallcovered {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n + 2];
        for (int i = 0; i < m; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            a[l]++;
            a[r + 1]--;
        }
        int cnt = 0;
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            cnt += a[i];
            if (cnt < ans)
                ans = cnt;
        }
        System.out.println(ans);
    }
} 