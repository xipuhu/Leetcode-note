/* ԭ������
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

// ��һ��ⷨ����
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

// ���ϺõĽⷨ
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

// �����Ż�
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

/* ˼��
1. �ⷨ˼·���棺

��̬�滮����ؼ����ǣ�Ҫ�ڱ����Ĺ����У�ͬʱ�����ѱ�������Ԫ���е���Сֵ��

2. ���������棺

���漰����Сֵ/���ֵ��ʱ��һ��Ҫ���ǵ�INT_MAX��INT_MIN������ֵ���Լ�max()��min()������������ͨ�����ǿ���ʹ������ӵļ��׶���
*/






