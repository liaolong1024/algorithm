class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        for (int i = len - 1; i >= 0; i--) {
            digits[i] += 1;
            if (digits[i] != 10)return digits;
            else digits[i] = 0;
        }
        int[] ans = new int[len+1];
        ans[0] = 1;
        return ans;
    }
}