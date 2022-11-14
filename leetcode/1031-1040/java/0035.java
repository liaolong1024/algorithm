/**
  二分查找
 */
class Solution {
    public int searchInsert(int[] nums, int target) {
        int len = nums.length;
        int low = 0, high = len - 1, mid;
        while (low <= high) {
            mid = low + ((high - low)>>1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return low;
    }
}