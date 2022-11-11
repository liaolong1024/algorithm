/**
  O(n^2)
 */
 class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        int tmp;
        int[] ans = new int[2];
        for (int i = 0; i < len; i++) {
            tmp = target - nums[i];
            for (int j = i+1; j < len; j++) {
                if (nums[j] == tmp) {
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
            }
        }
        return ans;
    }
}

/**
  O(n)
 */
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        int[] ans = new int[2];
        int tmp;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            tmp = target - nums[i];
            if (map.containsKey(tmp)) {
                ans[0] = i;
                ans[1] = map.get(tmp);
                break;
            }
            map.put(nums[i], i);
        }
        return ans;
    }
}