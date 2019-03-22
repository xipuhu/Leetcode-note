/* ԭ������
169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than [n/2] times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/


// ��һ��ⷨ����
/* info:
*Runtime: 28 ms, faster than 43.15%
*Memory Usage: 11.5 MB, less than 10.40%
*/
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> num_count;
    
    if(nums.size() == 1) return nums[0];
    
        int len = nums.size() / 2;
    
    for (auto num : nums){
        if (num_count.find(num) != num_count.end()){
            ++num_count[num];
            if (num_count[num] > len)
                return num;
        }
        else
            num_count.insert(make_pair(num, 1));
    }
    return 0;
}
/* info:
*Runtime: 28 ms, faster than 43.15%
*Memory Usage: 11.4 MB, less than 27.65%
*/
int majorityElement(vector<int>& nums) {

    int len = nums.size() / 2;
    int count = 1;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i){
        if (nums[i] == nums[i + 1]){
            ++count;
        if (count > len)
            return nums[i];
        }
        else
            count = 1;
    }

    return nums[0];
}

// ���ϺõĽⷨ
/* info:
*Runtime: 28 ms, faster than 43.15%
*Memory Usage: 11.3 MB, less than 62.83%
*/
int majorityElement(vector<int>& nums) {

    int len = nums.size() / 2;

    sort(nums.begin(), nums.end());

    return nums[len];
}

/* info:
*Runtime: 20 ms, faster than 98.94%
*Memory Usage: 11.3 MB, less than 39.38%
*/
int majorityElement(vector<int>& nums) {
    vector<int>::iterator mid = nums.begin() + nums.size()/2;
    nth_element(nums.begin(), mid, nums.end());
    return (*mid);
}

/* info:
*Runtime: 24 ms, faster than 61.46%
*Memory Usage: 11.2 MB, less than 75.66%
*/
int majorityElement(vector<int> &num) {
        int len = num.size();
        if (len < 3) return num[0];
        int half = len/2;
        int bit_ct[32];
        for (int i=0; i<32; ++i)  bit_ct[i] = 0;
        for (auto n:num){ // count the number of 1 occured on each bit position
            for (int i=0; i<32; ++i){
                if (n%2) ++bit_ct[i];
                n >>= 1;
            }
        }
        int ans = 0;
        for(int i=31; i>=0; --i){
            ans <<= 1;
            if (bit_ct[i]>half) ++ans;
        }
        return ans;
}



// �����Ż�
/* info:
*Runtime: 20 ms, faster than 98.91%
*Memory Usage: 11.3 MB, less than 57.96%
*/
int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate;

    for (auto num : nums){
        if (count == 0)
            candidate = num;

        count += (num == candidate) ? 1 : -1;
    }
    return candidate;

}
/* ˼��
1. �ⷨ˼·���棺

���ù�ϣ������¼ÿ��Ԫ�س��ֵĴ�����

�Ƚ�nums����һ������Ȼ�������źú��nums��ͳ�Ƴ��ִ������� nums.size()/2 ��Ԫ��

Boyer-MooreͶƱ�㷨����������ͬ��Ԫ��ʵ������Ϊ+1�������κ�����Ԫ�ص�ʵ������Ϊ-1�������ڱ����Ĺ��̽��м�����ͣ���ô����Ҫ�ҵ�Ԫ�س��ֵĴ�������num.size()/2��������һ�����һ�������ͺ����������϶��Ǵ���1�ģ���ʱ�򷵻ظö��ڵ�Ԫ�ؼ��ɡ�


2. ���������棺

C++��̬��ʼ�����飺һ������£�����һ�������ʱ���Ǳ���Ҫ�ṩһ��������ָ��ά�ȵĴ�С������ʱ��������Ҫ��̬����
�������Ĵ�С������������������Ǹ���ô���أ�
���ڶ�̬�����ʼ�������¼���ע�����
1��Ԫ��ֻ�ܳ�ʼ��ΪԪ�����͵�Ĭ��ֵ�����������������һ�����ó�ʼ���б�Ϊ����Ԫ���ṩ������ͬ�ĳ�ʼֵ��
2������������������Ԫ�ص����飬����ʹ��()����ʾָ������ִ�г�ʼ���������������ִ�г�ʼ��������
    int *arr1 = new int[10];         // ÿ��Ԫ�ض�û�г�ʼ��
    int *arr2 = new int[10]();       // ÿ��Ԫ�س�ʼ��Ϊ0
3������������Ԫ�ص����飬�������Ƿ�ʹ��()�������Զ������乹�캯������ʼ����
    string *str1 = new string[10];  // ÿ��Ԫ�ص���Ĭ�Ϲ��캯������ʼ��
    string *str2 = new string[10]() // ÿ��Ԫ�ص���Ĭ�Ϲ��캯������ʼ�� 

nth_element()����:
ͷ�ļ��� #include<algorithm>
���ã�nth_element����Ϊ���n���Ԫ�أ����������ڵ�nλ���ϣ��±��Ǵ�0��ʼ�����ģ�Ҳ����˵��0С��Ԫ�ؾ�����С������
���磺
int a[] = {1, 3, 4, 5, 2, 6, 8, 7, 9};
nth_element(a, a+5, a+9);
cout<<��������������<< a[4]<<endl; // ���5 �±��Ǵ�0��ʼ������

ʹ�÷�����nth_element(a+i, a+k, a+j)����������ʹa�������������(i, j)�ڵĵ�k���Ԫ�ش��ڵ�k��λ���ϣ����λ�ã�

ע�⣺nth_element()���������ǽ���n������ź���λ�ã���������ֵ��

*/




