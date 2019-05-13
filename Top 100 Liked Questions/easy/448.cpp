/* 原题内容
448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/


// 第一遍解法代码
/* info:
*Runtime: 120 ms, faster than 53.83%
*Memory Usage: 16.2 MB, less than 13.85%
*/
vector<int> findDisappearedNumbers(vector<int>& nums) {

    vector<int> nums_disappear = {};
    int *arr_tmp = new int[nums.size()+1]();

    if (nums.empty() || nums.size() == 1) return nums_disappear;

    for (auto num : nums)
        arr_tmp[num] = 1;

    for (int i = 1; i < nums.size()+1; ++i){
        if (arr_tmp[i] == 0)
            nums_disappear.push_back(i);
    }
	
    return nums_disappear;
}
/* info:
*Runtime: 116 ms, faster than 94.25%
*Memory Usage: 15 MB, less than 86.15%
*/
vector<int> findDisappearedNumbers(vector<int>& nums) {

    vector<int> nums_disappear = {};

    if (nums.empty() || nums.size() == 1) return nums_disappear;

    for (auto num : nums)
        while(nums[i] != nums[nums[i]-1])
            swap(nums[i], nums[nums[i] - 1]);  // 将nums[i]值交换到下标为nums[i]-1的数组位置上

    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] != i+1)
            nums_disappear.push_back(i+1);
    }
	
    return nums_disappear;
}

// 网上好的解法
/* info:
*Runtime: 112 ms, faster than 95.88%
*Memory Usage: 15 MB, less than 86.15%
*/
vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1;  // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
}
// 精简优化
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/

/* 思考
1. 解法思路方面：

在遍历数组nums的过程中，将nums[nums[i]-1]进行标记（可以将nums[i]交换给下标为nums[i]-1的元素，或者将该下标对应的元素值取负值）表示该元素存在。

2. 代码解决方面：

*/




