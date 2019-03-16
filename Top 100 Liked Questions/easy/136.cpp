/* ԭ������
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

// ��һ��ⷨ����
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
//�ڶ���ⷨ����
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

// ���ϺõĽⷨ
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

// �����Ż�
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

/* ˼��
1. �ⷨ˼·���棺

˼·1���Ƚ�nums����һ������������ٱ���һ�鼴�ɣ�

˼·2���ڱ���nums�Ĺ����У�ͨ��unordered_map���ظ�Ԫ�ؽ���ɸ��

˼·3����������λ���������н��⣨���n^n = 0, 0^n = n��


2. ���������棺

����ͨ��make_pair()��������mapԪ�ؽ���һ����ʼ��������

ע�⣬����map��˵���ǲ�����ͨ����������Ԫ�صĲ����ġ�

һЩ����λ����Ĺ����ܽ᣺������Զ������Զ����ڲ��������������£�������Զ������Զ��������漰����һ�������ǣ������Ƹ��������ʵ������������1�����������������ʵ������������0��

�����㣺
if(a & 1 == 0)  //ż��
if(a & 1 == 1)  //����
(n-1) & n       //��ȥn���һλ��1��������ͳ��n����λ��1�ĸ���
~(n-1) & n      //������n���һλ��1���������������mask (-n = ~(n-1))

������㣺
a ^ a = 0;      //��ͬ������0
a ^ 0 = 0;
a ^ b ^ a = b   //һ�������ͬһ�������ο��Ի�ԭ

//�������µı�������������������ֵ
//1.���ڼӼ���
a = a + b;
b = a - b;
a = a - b;
//2.�����������
a = a^b;
b = a^b;
a = a^b;

ȡ�����㣺
//-1�Ĳ���ȫΪ1
x + ~x = -1  // һ�������䷴�������Ϊ-1���Ƴ���-n = ~(n-1)
y + ~y = -1
x + y = 27, ��~x + ~y = -29


*/




