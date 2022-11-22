/**
   暴力双重循环遍历, 超时
 */
class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        int len = prices.length;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i+1; j < len; j++) {
                if (prices[i] < prices[j]) {
                    ans = Math.max(ans, prices[j]-prices[i]);
                }
            }
        }
        return ans;
    }
}

/**
  优化一: 买入股票如果比之前的计算过的买入股票价格高, 就不用计算了
  依旧超时
 */
class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, minPre = Integer.MAX_VALUE;
        int len = prices.length;
        for (int i = 0; i < len - 1; i++) {
            if (prices[i] > minPre) continue;
            for (int j = i+1; j < len; j++) {
                if (prices[i] < prices[j]) {
                    ans = Math.max(ans, prices[j]-prices[i]);
                }
            }
            minPre = Math.min(minPre, prices[i]);
        }
        return ans;
    }
}

/**
   算法: 其实就是自底向上的动态规划
      1. 遍历prices数组, 下标为idx
      2. 遍历过程中保存idx下标之前那些价格中的最低价格, 
         也就是在保证在第idx天, 我们是在的价格最低的时候买入的股票
      3. 如果第idx天可以获得利润, 计算并保存利润较大值
 */
class Solution {
  public int maxProfit(int[] prices) {
      int len = prices.length;
      
      int ans = 0;
      int minPriceBeforeIdx = Integer.MAX_VALUE;
      for (int idx = 0; idx < len; idx++) {
          if (minPriceBeforeIdx > prices[idx]) {
              minPriceBeforeIdx = prices[idx];
          } else {
              ans = Math.max(ans, prices[idx]-minPriceBeforeIdx);
          }
      }
      return ans;
  }
}