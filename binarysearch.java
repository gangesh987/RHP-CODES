import java.util.*;
public class binarysearch {
    static int search(int[] nums, int target) {
        int lt = 0, rt = nums.length - 1;
        while (lt + 1 < rt) {
            int mid = (lt + rt) / 2;
            if (nums[mid] < target) {
                lt = mid;
            } else {
                rt = mid;
            }
        }
        return nums[lt] == target ? lt : nums[rt] == target ? rt : -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int target = sc.nextInt();
        System.out.println(search(nums, target));
    }
}