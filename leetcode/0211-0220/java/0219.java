class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        int left = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i - left > k) {
                set.remove(nums[left++]);
            } 
            if (!set.add(nums[i])) {
                return true;
            } 
        }
        return false;
    }
}