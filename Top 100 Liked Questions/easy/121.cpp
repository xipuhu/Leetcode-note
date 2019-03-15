/* 原题内容
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

// 第一遍解法代码
/*  info:
*Runtime: 8 ms, faster than 99.43%
*Memory Usage: 9.3 MB, less than 99.29%
*/
int maxProfit(vector<int>& prices) {
	
    if (prices.empty()) return 0;

        int max_profit = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i){
            if (prices[i] < min_price)
                min_price = prices[i];

            if (prices[i] - min_price > max_profit)
                max_profit = prices[i] - min_price;
    }
	
    return max_profit;
}

// 网上好的解法
/* info:
*Runtime: 8 ms, faster than 99.43%
*Memory Usage: 9.5 MB, less than 67.98%
*/
int maxProfit(vector<int>& prices) {
    int res=0,buyp=INT_MAX;
    for(auto i:prices) {
        (i<buyp)?(buyp=i):res=max(i-buyp,res);
    }
    return res;
}

// 精简优化
/* info:
*Runtime: 8 ms, faster than 99.43%
*Memory Usage: 9.4 MB, less than 90.69%
*/
int maxProfit(vector<int>& prices) {

    if (prices.empty()) return 0;

    int max_profit = 0;
    int min_price = INT_MAX;
    for (int i = 0; i < prices.size(); ++i){
        min_price = min(prices[i], min_price);
        max_profit = max(prices[i] - min_price, max_profit);
    }

    return max_profit;
}

/* 思考
1. 解法思路方面：

动态规划：最关键的是，要在遍历的过程中，同时保存已遍历过的元素中的最小值。

2. 代码解决方面：

在涉及到最小值/最大值的时候，一定要考虑到INT_MAX和INT_MIN这两个值，以及max()和min()这两个函数，通过它们可以使代码更加的简单易懂。
*/






