/* 原题内容
136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4

*/

// 第一遍解法代码
/* info:
*Runtime: 24 ms, faster than 34.73%
*Memory Usage: 9.7 MB, less than 61.91%
*/
int singleNumber(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i+=2){
        if (nums[i] != nums[i + 1])
            return nums[i];
    }
    return nums[nums.size() - 1];
}
//第二遍解法代码
/* info:
*Runtime: 24 ms, faster than 35.17%
*Memory Usage: 11.3 MB, less than 19.75%
*/
int singleNumber(vector<int>& nums) {
    if (nums.size() == 1)  return nums[0];
    unordered_map<int, int> map;
    map.insert(make_pair(nums[0], 0));

    for (int i = 1; i < nums.size(); ++i){
        if (map.find(nums[i]) != map.end())
            map.erase(nums[i]);
        else 
            map.insert(make_pair(nums[i], i));
    }
    unordered_map<int, int>::iterator it = map.begin();

    return it->first;
}

// 网上好的解法
/* info:
*Runtime: 16 ms, faster than 97.28%
*Memory Usage: 9.6 MB, less than 88.80%
*/
// use xor: n^n = 0, 0^n = n
int singleNumber(vector<int>& nums) {
        int m = 0;
        for(int i=0;i<nums.size();i++) m^=nums[i];
        return m;
 }

// 精简优化
/* info:
*Runtime: 16 ms, faster than 97.28%
*Memory Usage: 9.6 MB, less than 88.80%
*/
// use xor: n^n = 0, 0^n = n
int singleNumber(vector<int>& nums) {
        int m = 0;
        for(auto it : nums)
	m^=it;
        return m;
 }

/* 思考
1. 解法思路方面：

思路1：先将nums进行一个排序操作，再遍历一遍即可；

思路2：在遍历nums的过程中，通过unordered_map对重复元素进行筛除

思路3：利用异或的位运算来进行解题（异或：n^n = 0, 0^n = n）


2. 代码解决方面：

可以通过make_pair()函数来对map元素进行一个初始化操作。

注意，对于map来说，是不存在通过索引访问元素的操作的。

一些关于位运算的规律总结：右移永远代表除以二，在不考虑溢出的情况下，左移永远代表乘以二；这里涉及到的一个规律是，二进制负数的左侧实际上有无数个1；二进制正数的左侧实际上有无数个0；

与运算：
if(a & 1 == 0)  //偶数
if(a & 1 == 1)  //奇数
(n-1) & n       //消去n最后一位的1，可用于统计n比特位上1的个数
~(n-1) & n      //仅保留n最后一位的1，可用于生成相关mask (-n = ~(n-1))

异或运算：
a ^ a = 0;      //相同数异或得0
a ^ 0 = 0;
a ^ b ^ a = b   //一个数异或同一个数两次可以还原

//不是用新的变量，交换两个变量的值
//1.基于加减法
a = a + b;
b = a - b;
a = a - b;
//2.基于异或运算
a = a^b;
b = a^b;
a = a^b;

取反运算：
//-1的补码全为1
x + ~x = -1  // 一个数与其反的数相加为-1，推出：-n = ~(n-1)
y + ~y = -1
x + y = 27, 故~x + ~y = -29


*/




