/* ԭ������
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// ��һ��ⷨ����
//ʱ�临�Ӷ�O(n^2) 144ms beats 35.96%
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

// ���ϺõĽⷨ
//����һ��ʹ��һ����ϣ���洢ÿ������Ӧ���±�,ʱ�临�Ӷȣ�O(n) 12ms beats 97.81%
vector<int> twoSum(vector<int> &nums, int target) {

    unordered_map<int, int> mapping;        //ʹ��map����Ϊ��16ms beats 57.75%

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

// �����Ż�
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
            return { hash_table[target - nums[i]], i };  // return {}��ʾ����һ��vector������ʱ��Ứ�ĸ���
            //return vector<int>{ hash_table[target - nums[i]], i };  // 12ms beats 97.81%
        hash_table.insert(pair<int, int>(nums[i], i));
    }
    return vector<int>();
}

/* ˼��
1. �ⷨ˼·���棺
   ������������������Ҫע��ģ�

������Ŀ���Ѿ���ȷ��һ�������һ�������Ҫ����˲���Ҫ�ڴ������ж��Ƿ��н⣬�����ı߽����⣻

��Ϊ����������nums[1]��nums[2]���������ض�����뵽��ϣ���У�ֻ��һ���Ⱥ����⣬�����ʹ�ù�ϣ���ʱ�򲢲���Ҫ��һ���԰�nums����Ԫ�ؼ��±���뵽��ϣ���У�ֻ��Ҫ�ڲ���Ԫ�ص���ϣ���е�ͬʱ�ж��Ƿ�������ĿҪ�󼴿ɡ�

2. ���������棺
   ����һ����Ӧ�õ���map����Ϊ��ϣ����ʹ�ã����������Ŀ֮ǰ����map��ʹ�ò��Ǻ�Ƶ�������ͨ�����⣬��map�����µ�һЩ˼����

�����Ƕ���map�Ĳ��룬��һ����Ҫע�⣬����ͨ��insert()����������Ԫ�ص�ʱ���ǻ����ж�Ҫ�����key�Ƿ��Ѿ����ڣ�����Ѿ����ڣ���������롣�������ͨ���±�����ֵ���룬��m[key]=new_value���Ḳ���Ѿ����ڵ�key��Ԫ�ء�

ʹ��find����������Ԫ��ʱ������������򷵻�m.end()�������ж��Ƿ��ҵ�Ӧ������ʹ�ã�if(m.find(key)!=m.end())

Map��unordered_map������map�ڲ�ʵ����һ����������ýṹ�����Զ�����Ĺ��ܣ����map�ڲ�������Ԫ�ض�������ģ��������ÿһ���ڵ㶼������map��һ��Ԫ�أ���ˣ�����map���еĲ��ң�ɾ������ӵ�һϵ�еĲ������൱���ǶԺ�������������Ĳ������ʺ������Ч�ʾ�����map��Ч��; ��unordered_map: unordered_map�ڲ�ʵ����һ����ϣ�������Ԫ�ص�����˳�������ҵģ�����ġ��ڲ��ҵ�ʱ��map��Ч��Ҫ��unordered_map�ͺܶࡣ

��map�У���key����valueʱ������Ҫ�ж�map���Ƿ����key���������飬ֱ�ӷ���map[key]�����ܻ�������벻������Ϊ�����map����key��û�����⣬���map������key��ʹ���±���һ��Σ�յĸ����ã�����map�в���һ��key��Ԫ�أ�valueȡĬ��ֵ������value��Ҳ����˵��map[key]�����ܷ���null��map�ṩ�����ַ�ʽ���鿴�Ƿ����key��m.count(key)��m.find(key)��
*/

