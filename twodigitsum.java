import java.util.*;

public class  twodigitsum{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {

            String a = sc.next();
            String b = sc.next();

            int n = a.length();
            int m = b.length();

            int[] pa = new int[n + 1];
            int[] pb = new int[m + 1];

            for (int i = 1; i <= n; i++)
                pa[i] = (pa[i - 1] + (a.charAt(i - 1) - '0')) % 10;

            for (int i = 1; i <= m; i++)
                pb[i] = (pb[i - 1] + (b.charAt(i - 1) - '0')) % 10;

            int[][] dp = new int[n + 1][m + 1];

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {

                    if (pa[i] == pb[j])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }

            int ans = dp[n][m];

            if (ans <= 0)
                System.out.println(-1);
            else
                System.out.println(ans);
        }
    }
}