import java.util.*;
public class ihatesigma {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] pre = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        long sum = 0;
        long last = 0;
        for (int i = n - 1; i >= 0; i--) {
            last -= pre[a[i]];
            pre[a[i]] = n - i;
            last += pre[a[i]];
            sum += last;
        }
        System.out.println(sum);
        sc.close();
    }
}