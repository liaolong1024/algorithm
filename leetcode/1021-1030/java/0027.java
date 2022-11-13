/*
  双指针, 起始点相同
*/
class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (val != nums[i]) {
                if (i > ans) {
                    nums[ans] = nums[i]; 
                }
                ans++;
            }
        }
        return ans;
    }
}

/**
  双指针优化, 起始点分别在头尾
 */
class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int left = 0, right = len - 1;
        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
}