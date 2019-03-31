/* ԭ������
283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/


// ��һ��ⷨ����
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
// ���ϺõĽⷨ
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
// �����Ż�
/* info:
*Runtime: 16 ms, faster than 99.46%
*Memory Usage: 9.4 MB, less than 94.91%
*/
void moveZeroes(vector<int>& nums) {
    fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
}
/* ˼��
1. �ⷨ˼·���棺



2. ���������棺

remove(first, last, val):����Χ[first��last]ת��Ϊ��һ����Χ[first,last_]���������е���val��Ԫ�ر��Ƴ����������������ص��÷�Χ���½�βlast_, ע�⣺�����Ĵ�С��û�з����ı䣬��[last_, last]������Ԫ�صġ�

fill(first, last, val):����Χ[first, last]��Ԫ��ȫ���滻Ϊval��

Remove��fillʹ�ã�#include<algorithm>

*/




