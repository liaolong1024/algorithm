/**
  额外使用O(m+n)空间
 */
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] tmp = new int[m+n];
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i == m) {
                tmp[i+j] = nums2[j++]; 
            } else if (j == n) {
                tmp[i+j] = nums1[i++];
            } else if (nums1[i] <= nums2[j]) {
                tmp[i+j] = nums1[i++];
            } else {
                tmp[i+j] = nums2[j++];
            }
        }
        for (int k = 0; k < m+n; k++) {
            nums1[k] = tmp[k];
        }
    }
}

/**
  不使用额外空间O(m+n)
 */
 class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] tmp = new int[m+n];
        int i = m - 1, j = n - 1, k = m+n-1;
        while (i >= 0 || j >= 0) {
            if (i == -1) {
                nums1[k--] = nums2[j--];
            } else if (j == -1) {
                break;
            } else if (nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
}