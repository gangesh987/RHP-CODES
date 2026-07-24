import java.util.*;

public class onedcountry {

    static int lowerBound(long[] a, long x) {
        int l = 0, r = a.length;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    static int upperBound(long[] a, long x) {
        int l = 0, r = a.length;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] > x)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long[] x = new long[n];
        for (int i = 0; i < n; i++)
            x[i] = sc.nextLong();

        long[] prefix = new long[n + 1];

        for (int i = 0; i < n; i++) {
            long p = sc.nextLong();
            prefix[i + 1] = prefix[i] + p;
        }

        int q = sc.nextInt();

        while (q-- > 0) {
            long L = sc.nextLong();
            long R = sc.nextLong();

            int left = lowerBound(x, L);
            int right = upperBound(x, R);

            System.out.println(prefix[right] - prefix[left]);
        }

        sc.close();
    }
}