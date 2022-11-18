class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>(numRows);
        for (int i = 0; i < numRows; i++) {
            List<Integer> elem = new ArrayList<>(i+1);
            if (i==0) elem.add(1);
            else {
                elem.add(1);
                List<Integer> pre = ans.get(i-1);
                for (int j = 1; j < pre.size(); j++){
                    elem.add(pre.get(j-1)+pre.get(j));
                }
                elem.add(1);
            }
            ans.add(elem);
        } 
        return ans;
    }
}