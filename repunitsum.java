import java.util.*;

public class repunitsum {

    static void solve() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] a = new int[n];
        ArrayList<Integer> ans = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);

        long cfwd = 0;

        for (int ctr = 1; ctr <= a[n - 1]; ctr++) {

            int idx = lowerBound(a, ctr);

            int cnt = n - idx;

            cfwd += cnt;

            ans.add((int) (cfwd % 10));

            cfwd /= 10;
        }

        while (cfwd != 0) {
            ans.add((int) (cfwd % 10));
            cfwd /= 10;
        }

        Collections.reverse(ans);

        for (int x : ans) {
            System.out.print(x);
        }

        System.out.println();
    }

    // Equivalent of C++ lower_bound()
    static int lowerBound(int[] a, int target) {
        int low = 0;
        int high = a.length;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (a[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }

    public static void main(String[] args) {
        solve();
    }
}