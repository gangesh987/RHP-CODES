import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int odd = 0, zero = 0, two = 0;
            while (n-- > 0) {
                int x = sc.nextInt();
                if (x % 2 != 0) odd++;
                else if (x % 4 == 0) zero++;
                else two++;
            }
            System.out.println(Math.max(odd, Math.max(zero, two)));
        }
    }
}