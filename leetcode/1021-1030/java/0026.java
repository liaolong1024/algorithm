class Solution {
    public int removeDuplicates(int[] nums) {
        int ans = 0;
        int len = nums.length;
        for (int i = 1; i < len; i++) {
            if (nums[ans] != nums[i]) {
                if (i - ans > 1) {
                    nums[ans+1] = nums[i];
                }
                ans++;
            }
        }
        return ans + 1;
    }
}