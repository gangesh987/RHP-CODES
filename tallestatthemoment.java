import java.util.*;
public class tallestatthemoment {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] height = new int[n];
        int[] leave = new int[n];
        for (int i = 0; i < n; i++) {
            height[i] = sc.nextInt();
            leave[i] = sc.nextInt();
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            int max = 0;
            for (int j = 0; j < n; j++) {
                if (leave[j] > t) {
                    max = Math.max(max, height[j]);
                }
            }
            System.out.println(max);
        }
    }
}