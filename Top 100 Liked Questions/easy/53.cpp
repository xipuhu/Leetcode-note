/* ԭ������
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

// ��һ��ⷨ����
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

// ���ϺõĽⷨ
/* info:
*Runtime: 8 ms, faster than 99.76%
*Memory Usage: 10.2 MB, less than 93.51%
*/
// ��̬�滮
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

// �����Ż�
/* info:
*Runtime: 12 ms, faster than 92.72%
*Memory Usage: 10.5 MB, less than 17.28%
*/
// ̰���㷨
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
// �����㷨
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
    Index cross_index;     // ע�ⲻҪֱ��ʹ��index����Ϊ���ֵ�޸Ĳ�����

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


/* ˼��
1. �ⷨ˼·���棺

��̬�滮��
    ��Ϊ���Ǹ��Ż����⡣����������Էֽ�Ϊһ���������⣬��������DP�������������һ�ֺܺõĽ��������dp[i-1]��dp[i]��ת�������������
    1) dp[i-1] > 0�� ������0ʱ��dp[i] = dp[i-1] + num[i]
    2) dp[i-1] < 0��������0ʱ��dp[i] = 0  ����Ϊ��ʱ���޳�dp[i-1]��Ӱ�죩

̰��:
    �����һ�������ʱ�ҵ��ܺ����Ž⣬��dp���ƣ������������ﲻ����dp��״̬��ֻ��¼��ʱsum�����sum

���η�:
    ���η���˼·�ǽ����ⲻ�϶��֣��ֵ������ٷ֣�Ȼ���ٽ���������������Ϲ�һ�����ó����Ž⣬�����ͼ��ʾ�������鲻�϶��֣�Ȼ��ȡ��ÿһ�ε����sum��Ȼ�󴫻��ܺ�����Ȼ��������Ž�.


2. ���������棺

max\min����������algorithmͷ�ļ���

INT_MIN\INT_MAX�ڱ�׼ͷ�ļ�limits.h�ж��壺
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

ʹ����������־��������С���������������ʱ��һ��Ҫע���Ƿ�������������

��һ�������У���Ҫֱ��ʹ�ú����Ĳ�������Ϊ����Ҫ���صĽ��ֵ������Ӧ����������һ���������洢����Ҫ���صĽ�������������׸�졣

*/




