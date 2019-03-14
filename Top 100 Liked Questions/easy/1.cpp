/* 原题内容
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// 第一遍解法代码
//时间复杂度O(n^2) 144ms beats 35.96%
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> indices;

    for (int i = 0; i < nums.size(); ++i){
        for (int j = i + 1; j < nums.size(); ++j){
            if (nums[j] + nums[i] == target){
                indices.push_back(i);
	     indices.push_back(j);
                break;
            }
        }
        if (!indices.empty())
	break;
    }

    return indices;
}

// 网上好的解法
//方法一：使用一个哈希表，存储每个数对应的下标,时间复杂度：O(n) 12ms beats 97.81%
vector<int> twoSum(vector<int> &nums, int target) {

    unordered_map<int, int> mapping;        //使用map后结果为：16ms beats 57.75%

    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        mapping[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
        const int gap = target - nums[i]; 
        if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
            result.push_back(i); 
            result.push_back(mapping[gap]); 
            break;
        }
    } 
    return result;
}

// 精简优化
//12ms beats 97.81%
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_table;
    vector<int> indices;

    for (int i = 0; i < nums.size(); ++i){
		
        if (hash_table.find(target - nums[i]) != hash_table.end()){
	
	indices.push_back(hash_table[target - nums[i]]);
	indices.push_back(i);
	break;
        }

        hash_table.insert(pair<int, int>(nums[i], i));
    }

    return indices;
}
//20ms beats 43.68%
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_table;
    for (int i = 0; i < nums.size(); ++i){
		
        if (hash_table.find(target - nums[i]) != hash_table.end())
            return { hash_table[target - nums[i]], i };  // return {}表示返回一个vector，但是时间会花的更多
            //return vector<int>{ hash_table[target - nums[i]], i };  // 12ms beats 97.81%
        hash_table.insert(pair<int, int>(nums[i], i));
    }
    return vector<int>();
}

/* 思考
1. 解法思路方面：
   本题有两个技巧是需要注意的：

首先题目里已经明确了一定会存在一组解满足要求，因此不需要在代码中判断是否有解，即题解的边界问题；

因为满足条件的nums[1]和nums[2]这两个数必定会插入到哈希表中，只是一个先后问题，因此在使用哈希表的时候并不需要先一次性把nums所有元素及下标插入到哈希表中，只需要在插入元素到哈希表中的同时判断是否满足题目要求即可。

2. 代码解决方面：
   在这一题中应用到了map来作为哈希表来使用，遇到这道题目之前对于map的使用不是很频繁，因此通过此题，对map有如下的一些思考：

首先是对于map的插入，有一点需要注意，就是通过insert()方法来插入元素的时候，是会先判断要插入的key是否已经存在，如果已经存在，则放弃插入。而如果是通过下标来赋值插入，即m[key]=new_value，会覆盖已经存在的key的元素。

使用find函数来查找元素时，如果不存在则返回m.end()，所以判断是否找到应该这样使用：if(m.find(key)!=m.end())

Map和unordered_map的区别：map内部实现了一个红黑树，该结构具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素，因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行这样的操作，故红黑树的效率决定了map的效率; 而unordered_map: unordered_map内部实现了一个哈希表，因此其元素的排列顺序是杂乱的，无序的。在查找的时候，map的效率要比unordered_map低很多。

在map中，由key查找value时，首先要判断map中是否包含key。如果不检查，直接返回map[key]，可能会出现意想不到的行为。如果map包含key，没有问题，如果map不包含key，使用下标有一个危险的副作用，会在map中插入一个key的元素，value取默认值，返回value。也就是说，map[key]不可能返回null。map提供了两种方式，查看是否包含key，m.count(key)，m.find(key)。
*/

