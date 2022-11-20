class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>(rowIndex+1);

        ans.add(1);
        if (rowIndex == 0) {
            return ans;
        }

        // 二项展开公式
        long tmp;
        for (int i = 1; i <= rowIndex / 2; i++) {
            // 使用long存储防止越界
            tmp = (long) ans.get(i-1) * (rowIndex+1-i);
            ans.add((int)(tmp / i));
        }
        
        for (int i = (rowIndex-1) / 2 ; i >= 0; i--) {
            ans.add(ans.get(i));
        }
        return ans;
    }
}