import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N, K;
            N = sc.nextInt();
            K = sc.nextInt();
            String s;
            s = sc.next();
            int F = N / K;
            boolean[] own = new boolean[F];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '0') {
                    int farmidx = i / K;
                    own[farmidx] = true;
                }
            }
            int count = 0;
            for (int f = 0; f < F; f++) {
                if (!own[f])
                    count++;
            }
            System.out.println(count);
        }
    }
}