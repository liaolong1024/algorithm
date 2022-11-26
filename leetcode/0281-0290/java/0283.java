/**
  双指针
 */
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> hashset = new HashSet<>();
        for (int num: nums) {
            hashset.add(num);
        }
        return hashset.size() != nums.length;
    }
}