 
 /**
  双指针: 移动高度较低的指针才有可能获取到更大的容量
  */
 class Solution {
    public int maxArea(int[] height) {
        int ans = 0;
        int len = height.length;
        int left = 0, right = len - 1;
        int h, l;
        while (left < right) {
            l = right - left;
            if (height[left] <= height[right]) {
                h = height[left];
                left++;
            } else {
                h = height[right];
                right--;
            }
            ans = Math.max(ans, l * h);
        }
        return ans;
    }
}