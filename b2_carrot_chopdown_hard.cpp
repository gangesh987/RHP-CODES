    #include <bits/stdc++.h>
    using namespace std;
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t;
        cin >> t;
        while (t--) {
            int n, m, k;
            cin >> n >> m >> k;
            vector<int> cnt(m + 1), suf(m + 2);
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                cnt[x]++;
            }
            for (int i = m; i >= 1; i--)
                suf[i] = suf[i + 1] + cnt[i];
            long long ans = 0;
            for (int x = 1; x <= m; x++) {
                long long cur = 0;
                for (int j = 0; j < k; j++) {
                    long long v = 1LL * x * (1LL << j);
                    if (v > m) break;
                    cur += suf[v];
                }
                ans = max(ans, cur);
            }
            cout << ans << '\n';
        }
    }

    import java.util.*;

public class Main {

    static void solve(Scanner sc) {

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] count = new int[m + 1];
        int[] prefixSum = new int[m + 1];

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            count[x]++;
        }

        for (int i = 1; i <= m; i++) {
            prefixSum[i] = prefixSum[i - 1] + count[i];
        }

        long[] answer = new long[m + 1];

        int limit = Math.min(18, m);

        for (int cut = 1; cut <= limit; cut++) {

            long maximum = 0;

            for (int x = 1; x <= m; x++) {

                long current = 0;

                for (int mul = 1; mul * x <= m; mul++) {

                    int left = mul * x;
                    int right = Math.min(left + x - 1, m);

                    long value = Math.min(
                        (long) mul,
                        (1L << cut) - 1
                    );

                    current += value *
                        (prefixSum[right] - prefixSum[left - 1]);
                }

                long position = (1L << cut) * x;

                if (position <= m) {
                    current += count[(int) position];
                }

                maximum = Math.max(maximum, current);
            }

            answer[cut] = maximum;
        }

        StringBuilder output = new StringBuilder();

        for (int cut = 1; cut <= m; cut++) {

            output.append(answer[Math.min(cut, 18)]);

            if (cut < m) {
                output.append(" ");
            }
        }

        System.out.println(output);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            solve(sc);
        }
    }
}