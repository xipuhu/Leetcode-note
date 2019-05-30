/* ԭ������
581. Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

*/


// ��һ��ⷨ����
/* info:
*Runtime: 44 ms, faster than 56.89%
*Memory Usage: 11.5 MB, less than 58.46%
*/
int findUnsortedSubarray(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1 || is_sorted(nums.begin(), nums.end())) return 0;

    vector<int> tmp(nums);
    int start = -1, end = -1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < tmp.size(); ++i){
        if (tmp[i] != nums[i]){
            if (start == -1)
                start = i;
            else
                end = i+1;
        }
    }
    return (end - start);
}
// ���ϺõĽⷨ
/* info:
*Runtime: 36 ms, faster than 91.56%
*Memory Usage: 10.6 MB, less than 79.26%
*/
int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int m = nums[0], n = nums.size(), left = n, right = -1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < m)
                right = i;
            m = max(m, nums[i]);
        }
        m = nums[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > m)
                left = i;
            m = min(m, nums[i]);
        }
        return max(0, right - left + 1);
}
// �����Ż�
/* info:
*Runtime: 36 ms, faster than 91.56%
*Memory Usage: 10.5 MB, less than 89.06%
*/
int findUnsortedSubarray(vector<int>& nums) {
        int n= nums.size(),  l=-1, r =-2, mn=nums[n-1], mx=nums[0];

        for(int i=0; i<n; ++i){
            mx = max(nums[i], mx);
            if(nums[i] < mx) r = i;

            mn = min (nums[n-1-i], mn);
            if(nums[n-1-i] >mn) l=n-1-i;

        }
        return r-l+1;
}
/* ˼��
1. �ⷨ˼·���棺

������������������ԭ����Ƚϣ�������ͬ������ʱֹͣ�������м�һ�ξ���������������������ˡ�

��ǰ��ʼѰ�����ֵ�� �������Ԫ��С����ǰ������ֵ����ȷ��Ϊ�ұ߽硣�Ӻ�ʼѰ����Сֵ����������Ԫ�ش�����������Сֵ����ȷ��Ϊ��߽硣��ʼ��l=-1, r =-2����Ϊȷ����̵������ԭ���������Ϊ�㡣

2. ���������棺

�ж�nums�Ƿ��Ѿ��ź���is_sorted(nums.begin(), nums.end())

*/




