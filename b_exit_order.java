import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int start = 1;
        int end = 10;
        for (int count = 1; count <= n; count++) {
            int curr = sc.nextInt();
            if (!(curr >= start && curr <= end)) {
                System.out.println("No");
                return;
            }
            if (count % 10 == 0) {
                start += 10;
                end += 10;
            }
        }
        System.out.println("Yes");
    }
}