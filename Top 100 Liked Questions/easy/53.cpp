/* 原题内容
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

// 第一遍解法代码
/* info:
*Runtime: 8 ms, faster than 100.00%
*Memory Usage: 10.4 MB, less than 33.46%
*/
int maxSubArray(vector<int>& nums) {

    int s1, maxsum;
    s1 = maxsum = nums[0];
    for (int i = 1; i < nums.size(); ++i){
        s1 += nums[i];
        if (s1 > nums[i] && s1 > maxsum)
            maxsum = s1;
        else if (nums[i] >= s1 ){
            if (nums[i] > maxsum)
                s1 = maxsum = nums[i];
            else
                s1 = nums[i];
        }		
    }

    return maxsum;
}

// 网上好的解法
/* info:
*Runtime: 8 ms, faster than 99.76%
*Memory Usage: 10.2 MB, less than 93.51%
*/
// 动态规划
int maxSubArray(vector<int>& nums) {
    int max=INT_MIN,sum=0,i,size=nums.size();
    for(i=0;i<size;i++){
        sum+=nums[i];
        if(max<sum)
            max=sum;
        if(sum<0)
            sum=0;
    }
    return max;
}
/* info:
*Runtime: 12 ms, faster than 92.72%
*Memory Usage: 10.5 MB, less than 20.59%
*/
int maxSubArray(vector<int>& nums){
    if(nums.empty())
        return 0;
    
    int result = nums[0];
    int size = nums.size();
    
    for(int i=1;i<size;i++)
        if(nums[i-1] > 0)
            nums[i] += nums[i-1];
    
    for(int i=0;i<size;i++)
        if(result < nums[i])
            result = nums[i];
    
    return result;
}

// 精简优化
/* info:
*Runtime: 12 ms, faster than 92.72%
*Memory Usage: 10.5 MB, less than 17.28%
*/
// 贪心算法
int maxSubArray(vector<int>& nums){
    int maxSum = nums[0];
    int curSum = 0;

    for (auto it : nums){
        curSum = max(curSum + it, it);
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}
/* info:
*Runtime: 12 ms, faster than 91.56%
*Memory Usage: 10.5 MB, less than 13.36%
*/
// 分治算法
struct Index
{
    int low;
    int maxsum;
    int high;

    Index() : low(0), maxsum(INT_MIN), high(0){}

};

Index findCrossMaxsum(vector<int>& arr, Index index, int mid){
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;

    int curSum = 0;
    Index cross_index;     // 注意不要直接使用index来作为结果值修改并返回

    for (int i = mid; i >= index.low; --i){
        curSum += arr[i];
        if (curSum > left_sum){
            left_sum = curSum;
            cross_index.low = i;
        }

    }

    curSum = 0;
    for (int j = mid + 1; j <= index.high; ++j){
        curSum += arr[j];
        if (curSum > right_sum){
            right_sum = curSum;
            cross_index.high = j;
        }
    }

    cross_index.maxsum = left_sum + right_sum;

    return cross_index;
}
Index findMaxSubArray(vector<int>& arr, Index index){
    if (index.low == index.high){
        index.maxsum = arr[index.low];
        return index;
    }
		
    else{
        Index left, right, cross;

        int mid = (index.low + index.high) / 2;
		
        left.low = index.low;
        left.high = mid;
        right.low = mid + 1;
        right.high = index.high;

        cross = findCrossMaxsum(arr, index, mid);
        left = findMaxSubArray(arr, left);
        right = findMaxSubArray(arr, right);
		
        if (left.maxsum >= right.maxsum && left.maxsum >= cross.maxsum)
            return left;
        else if (right.maxsum >= cross.maxsum && right.maxsum >= left.maxsum)
            return right;
        else
            return cross;

        }
}
int maxSubArray(vector<int>& nums){

    Index index, result;
    index.low = 0;
    index.high = nums.size() - 1 ;

    result = findMaxSubArray(nums, index);

    return result.maxsum;
}


/* 思考
1. 解法思路方面：

动态规划：
    因为这是个优化问题。并且问题可以分解为一个个子问题，所以利用DP来解决此问题是一种很好的解决方案：dp[i-1]到dp[i]的转换分两种情况：
    1) dp[i-1] > 0： 当大于0时，dp[i] = dp[i-1] + num[i]
    2) dp[i-1] < 0：当大于0时，dp[i] = 0  （因为此时将剔除dp[i-1]的影响）

贪心:
    从左到右汇总数组时找到总和最优解，和dp类似，但是我们这里不保存dp的状态，只记录临时sum和最大sum

分治法:
    分治法的思路是将问题不断二分，分到不能再分，然后再将计算完的数据整合归一，最后得出最优解，这里，如图所示，将数组不断二分，然后取出每一段的最大sum，然后传回总函数，然后输出最优解.


2. 代码解决方面：

max\min函数包含在algorithm头文件中

INT_MIN\INT_MAX在标准头文件limits.h中定义：
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

使用这两个标志来代表最小整数和最大整数的时候，一定要注意是否存在溢出的问题

在一个函数中，不要直接使用函数的参数来作为函数要返回的结果值变量，应该另外声明一个变量来存储函数要返回的结果，这样不容易搞混。

*/





