/* 原题内容
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

// 第一遍解法代码
/* info:
*Runtime:  4 ms, faster than 100.00%
*Memory Usage: 8.7 MB, less than 32.08%
*/
int climbStairs(int n) {

    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    vector<int> fb;
    fb.push_back(1);
    fb.push_back(2);

    int i;
    for (i = 2; i < n; ++i){
        fb.push_back(fb[i - 2] + fb[i - 1]);
    }
    return fb[i - 1];
}

// 网上好的解法
/* info:
*Runtime:  4 ms, faster than 100.00%
*Memory Usage: 8.5MB, less than 59.00%
*/
int climbStairs(int n) {
        int i, wayN_1=1, wayN_2=1;
        int res = 1;
        if(n<2)
            return res;
        else
        {
            i=2;
            while(i<=n)
            {
                wayN_2 = wayN_1;
                wayN_1 = res;
                res = wayN_1 + wayN_2;
                i++;
            }
            return res;
        }
 }
/* info:
*Runtime:  4 ms, faster than 100.00%
*Memory Usage: 8.3MB, less than 90.02%
*/
int climbStairs(int n) {
       int x[3]={1,1,0},k=1;
       while(++k<=n)    x[k%3] = x[(k-1)%3] + x[(k-2)%3];
       return x[n%3];
}
/* info:
*Runtime:  ms, faster than %
*Memory Usage: MB, less than %
*/
int climbs(int n,vector<int>& r){
    if(r[n] != 0)
        return r[n];
    if(n > 1){
        r[n] = climbs(n-1,r)+climbs(n-2,r);
    }
    return r[n];
}

int climbStairs(int n){

    vector<int> r(n+1,0);
    r[1] = 1;
    r[2] = 2;
    int ans = climbs(n,r);
    return ans;

}

// 精简优化
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28% 
*/
int climbStairs(int n){	
    int result;
    result = (1 / sqrt(5)) * (pow((1 + sqrt(5)) / 2, n+1) - pow((1 - sqrt(5)) / 2, n+1));

    return result;

}

/* 思考
1. 解法思路方面：

本题可以利用斐波纳契数列(Fibonacci)的规律进行解题

斐波纳契数列的计算公式如下：
      
2. 代码解决方面：
*/





