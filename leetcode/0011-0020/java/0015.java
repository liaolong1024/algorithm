class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();

        // 排序
        Arrays.sort(nums);

        int len = nums.length;
        // 上一个遍历的a值, b值
        int aPre = 0;
        int bPre = 0;

        for (int i = 0; i < len; i++) {
            // 固定a值, 寻找b, c
            int a = nums[i];
            // 如果和上一次遍历的值一样, 就没有遍历的必要了
            if (i != 0 && a == aPre) {
                continue;
            }
            aPre = a;

            // j指针, 指向当前a位置的下一个位置
            int j = i+1;
            // k指针, 指向最后一个元素
            int k = len -1;

            // 记录下面这个while循环上一次遍历的j
            int prej = j;
            while (j < k) {
                // 固定b寻找c
                int b = nums[j];
                // 如果此次循环相比上一次循环j指针发生了变化, 判断是否与上一次的b值一样, 如果一样, 则不需要遍历
                if (j != prej && b == bPre) {
                    prej = j;
                    j++;
                    continue;
                }
                bPre = b;
                prej = j;


                int c = nums[k];
                // c满足等式, 加入到结果集中, k左侧的元素都小于等于c, 
                // 当前b不再会有符合条件的元素, 故j++, 此时b增大, c应当选取更小的数, 故k--
                if (a+b+c==0) {
                    ans.add(Arrays.asList(a,b,c));
                    k--;
                    j++;
                // 因为b偏小而不满足等式, 故j右移, 获取更大的b以满足等式
                } else if (a+b+c < 0) {
                    j++;
                // 因为c偏大而不满足等式, 故k左移, 尝试获取更小的c以满足等式
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
}