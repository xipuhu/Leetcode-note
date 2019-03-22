/* 原题内容
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


// 第一遍解法代码
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

// 网上好的解法
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



// 精简优化
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
/* 思考
1. 解法思路方面：

利用哈希表来记录每个元素出现的次数。

先将nums进行一个排序，然后利用排好后的nums来统计出现次数大于 nums.size()/2 的元素

Boyer-Moore投票算法：将多数相同的元素实例计数为+1，并将任何其他元素的实例计数为-1，这样在遍历的过程进行计数求和，那么由于要找的元素出现的次数大于num.size()/2，因此完成一遍遍历一遍计数求和后，其计数结果肯定是大于1的，这时候返回该对于的元素即可。


2. 代码解决方面：

C++动态初始化数组：一般情况下，声明一个数组的时候是必须要提供一个常量来指明维度的大小，但有时候我们需要动态地来
设计数组的大小，遇到这种情况，我们该怎么办呢？
关于动态数组初始化有如下几点注意事项：
1）元素只能初始化为元素类型的默认值，而不能像数组变量一样，用初始化列表为数组元素提供各不相同的初始值；
2）对于内置数据类型元素的数组，必须使用()来显示指定程序执行初始化操作，否则程序不执行初始化操作：
    int *arr1 = new int[10];         // 每个元素都没有初始化
    int *arr2 = new int[10]();       // 每个元素初始化为0
3）对于类类型元素的数组，则无论是否使用()，都会自动调用其构造函数来初始化：
    string *str1 = new string[10];  // 每个元素调用默认构造函数来初始化
    string *str2 = new string[10]() // 每个元素调用默认构造函数来初始化 

nth_element()函数:
头文件： #include<algorithm>
作用：nth_element作用为求第n大的元素，并把它放在第n位置上，下标是从0开始计数的，也就是说第0小的元素就是最小的数。
比如：
int a[] = {1, 3, 4, 5, 2, 6, 8, 7, 9};
nth_element(a, a+5, a+9);
cout<<”第五大的数：”<< a[4]<<endl; // 输出5 下标是从0开始计数的

使用方法：nth_element(a+i, a+k, a+j)，这样它会使a这个数组中区间(i, j)内的第k大的元素处在第k个位置上（相对位置）

注意：nth_element()函数不过是将第n大的数排好了位置，并不返回值。

*/




