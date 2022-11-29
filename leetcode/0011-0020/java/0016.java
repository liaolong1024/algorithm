/**
  与15题类似, 双指针
 */
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int len = nums.length;
        int ans = target < 0 ? 4000 : -4000;
        int a, b, c, p, q, sum;
        for (int i = 0; i < len; i++) {
            a = nums[i];
            p = i+1;
            q = len -1;
            while (p < q) {
                b = nums[p];
                c = nums[q];
                sum = a + b + c;
                if (sum < target) {
                    p++;
                } else if (sum > target) {
                    q--;
                } else {
                    return target;
                }
                if (Math.abs(sum-target) < Math.abs(ans-target)) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
}