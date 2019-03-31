/* 原题内容
283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/


// 第一遍解法代码
/* info:
*Runtime: 36 ms, faster than 5.33%
*Memory Usage: 9.3MB, less than 100.00%
*/
void moveZeroes(vector<int>& nums) {

    if (nums.empty() || nums.size() == 1) return;
	
    int zero_num = 0;
    int i = 0;
    while(i < nums.size()){
        if (nums[i] == 0){
            for (int j = i; j < nums.size() - zero_num - 1; ++j)
                swap(nums[j], nums[j + 1]);
            ++zero_num;
        }
        if (i + zero_num >= nums.size() - 1)
            return;
        if (nums[i] != 0)
            ++i;
    }
}

/* info:
*Runtime: 36 ms, faster than 5.33%
*Memory Usage: 9.3MB, less than 100.00%
*/
void moveZeroes(vector<int>& nums) {

    if (nums.empty() || nums.size() == 1) return;

    int index = 1;
    int curr_index = 0;
    while (index < nums.size() && curr_index < nums.size()){
        if (nums[curr_index] == 0){
            swap(nums[curr_index], nums[index++]);
        }
        if (nums[curr_index] != 0){
            ++curr_index;
            index = curr_index + 1;
        }
    }
}
// 网上好的解法
/* info:
*Runtime: 16 ms, faster than 99.46%
*Memory Usage: 9.7 MB, less than 19.96%
*/
void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    // Count the zeroes
    int numZeroes = 0;
    for (int i = 0; i < n; i++) {
        numZeroes += (nums[i] == 0);
    }

    // Make all the non-zero elements retain their original order.
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            ans.push_back(nums[i]);
        }
    }

    // Move all zeroes to the end
    while (numZeroes--) {
        ans.push_back(0);
    }

    // Combine the result
    for (int i = 0; i < n; i++) {
        nums[i] = ans[i];
    }
}

/* info:
*Runtime: 24 ms, faster than 26.55%
*Memory Usage: 9.3 MB, less than 100.00%
*/
void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}
// 精简优化
/* info:
*Runtime: 16 ms, faster than 99.46%
*Memory Usage: 9.4 MB, less than 94.91%
*/
void moveZeroes(vector<int>& nums) {
    fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
}
/* 思考
1. 解法思路方面：



2. 代码解决方面：

remove(first, last, val):将范围[first，last]转换为另一个范围[first,last_]，其中所有等于val的元素被移除，并将迭代器返回到该范围的新结尾last_, 注意：容器的大小并没有发生改变，即[last_, last]还是有元素的。

fill(first, last, val):将范围[first, last]的元素全都替换为val。

Remove和fill使用：#include<algorithm>

*/




