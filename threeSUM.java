import java.util.*;
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        int N = nums.length;
        for (int i = 0; i < N - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int lt = i + 1;
            int rt = N - 1;
            while (lt < rt) {
                int sum = nums[i] + nums[lt] + nums[rt];
                if (sum == 0) {
                    res.add(Arrays.asList(nums[i], nums[lt], nums[rt]));
                    while (lt < rt && nums[lt] == nums[lt + 1]) lt++;
                    while (lt < rt && nums[rt] == nums[rt - 1]) rt--;
                    lt++;
                    rt--;
                } else if (sum < 0) {
                    lt++;
                } else {
                    rt--;
                }
            }
        }
        return res;
    }
}