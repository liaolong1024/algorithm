/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return createTree(nums, 0, nums.length-1);
    }

    public TreeNode createTree(int[] nums, int start, int end) {
        int mid = start + ((end-start)>>1);
        TreeNode midNode = new TreeNode(nums[mid]);
        if (mid-1 >= start) midNode.left = createTree(nums, start, mid-1);
        if (mid+1 <= end) midNode.right = createTree(nums, mid+1, end);
        return midNode;
    }
}