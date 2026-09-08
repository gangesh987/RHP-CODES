import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int first = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] == 1) {
                    first = i;
                    break;
                }
            }
            int last = -1;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == 1) {
                    last = i;
                    break;
                }
            }
            if (first == -1) {
                for (int i = 0; i < n; i++) {
                    if (a[i] == -1) {
                        a[i] = 1;
                        break;
                    }
                }
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] == -1) {
                        a[i] = 1;
                        break;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (a[i] == -1) {
                    a[i] = 0;
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.print(a[i] + " ");
            }
            System.out.println();
        }
    }
}