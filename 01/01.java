import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int cur = nums[i];
            int complement = target - cur;
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }

            map.put(cur, i);
        }
        return new int[0];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] result = solution.twoSum(new int[] { 2, 7, 11, 15 }, 9);
        for (int i : result) {
            System.out.print(String.format("%d ", i));
        }
        System.err.println();
    }
}