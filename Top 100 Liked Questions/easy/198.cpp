/* ԭ������
198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

*/


// ��һ��ⷨ����
/* info:
*Runtime: 4 ms, faster than 100.00%
*Memory Usage: 8.9 MB, less than 63.32%
*/
int rob(vector<int>& nums) {

    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);

    int n = nums.size();

    int *dp = new int[n];

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i){
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }

    return dp[n - 1];
}
// ���ϺõĽⷨ
/* info:
*Runtime: 4 ms, faster than 100.00%
*Memory Usage: 8.9 MB, less than 81.31%
*/
int rob(vector<int>& nums) {
        
    priority_queue<int> pq;
    for(int i=2;i<nums.size();i++){
        pq.push(nums[i-2]);
        auto maxsub = pq.top();
        if(maxsub + nums[i] > nums[i-1])
            nums[i] += maxsub;
        else
            nums[i] = nums[i-1];
    }
    
    int maxprofit = 0;
    for(auto& x:nums){
        maxprofit = max(maxprofit,x);
    }
    return maxprofit;
        
}

/* info:
*Runtime: 4 ms, faster than 100.00%
*Memory Usage: 8.8 MB, less than 91.82%
*/
int rob(std::vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    std::vector<int> dp(n+2);        //all elements initialized to 0 by default

    for(int i = 2; i < n+2; ++i){
        dp[i] = std::max(dp[i-2] + nums[i-2], dp[i-1]);
    }
    return dp[n+1];
}

// �����Ż�
/* info:
*Runtime: 4 ms, faster than 100.00%
*Memory Usage: 8.8 MB, less than 97.66%
*/
int rob(vector<int>& nums) {

    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);

    int n = nums.size();
    int *dp = new int[3]();

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i){
        dp[i % 3] = max(dp[(i - 1) % 3], nums[i] + dp[(i - 2) % 3]);
    }

    return max(max(dp[0], dp[1]), dp[2]);
}
/* ˼��
1. �ⷨ˼·���棺

��̬�滮��dp��������nums�����ǿ����ڱ�����ͬʱ��¼��Ŀǰnums[i]��Ӧ���ܻ�õ���߽��������ڵ�Ԫ�ز�����ͣ������������dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])�����㡣

��̬�滮С�᣺�ڼ�����һ�������ʱ����Ҫ�ο���һ�εĽ���������Ҫ�ڱ���������Ĺ�����ͬʱ����á����εĽ�������Ա���Ϊ��һ�μ���Ĳο�ֵ�������������㡰���εĽ����������Ҫ������Ŀ��������Ϣ��ȷ����

2. ���������棺

���˿���ʹ��ָ�����ʽ����̬��������Ĵ�С�����ǻ�����ʹ��vector<int> arr(n)��ģ�⶯̬��С�����ʹ�ã���������Ҫ�ǽ�����vector�Ĺ��캯������̬������n�����ͱ�����

�������ȶ���priority_queue�����ȼ�������һ������������������һЩ�ϸ���������׼��ר�����ʹ���һ��Ԫ��ʼ���������������Ԫ�ء�

priority_queue ģ����3������������������Ĭ�ϵĲ�������һ�������Ǵ洢��������ͣ��ڶ��������Ǵ洢Ԫ�صĵײ������������������Ǻ�������Ĭ����less����������һ����������Ԫ��˳��Ķ��ԡ����ģ�������ǣ�
template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue

�������ӣ�
    #if 1
    #include <iostream>
    #include <queue>
    using namespace std;
    struct Node{
	    int x, y;
	    Node(int a = 0, int b = 0) :
		    x(a), y(b) {}
    };
    struct cmp{
	    bool operator() (Node a, Node b){          //Ĭ����less����

		    //����trueʱ��a�����ȼ�����b�����ȼ���a����b�ĺ��棩
		    if (a.x == b.x) return a.y > b.y;
		    return a.x> b.x;
	    }
    };
    int main(){
	    priority_queue<Node, vector<Node>, cmp> q;
	    for (int i = 0; i< 10; ++i)
		    q.push(Node(rand(), rand()));
	    while (!q.empty()){
		    cout << q.top().x << ' ' << q.top().y << endl;
		    q.pop();
	    }

	    system("pause");
	    return 0;
    }
    #endif

greater ��less:��ͷ�ļ�<functional>���棬greater��less�������˲�����
����һ����sort������ʱ��greater��less������Ϊ����ָ�봫����ȥ������Ҫ����д�ȽϺ�����Ϊ����ָ�봫�ݸ�sort�����ĵ���������
  #if 1
    #include <iostream>
    #include <algorithm>
    #include <functional>
 
    using namespace std;
 
    int main(){
        int nums[] = {5, 3, 1, 2, 4};
        int length = sizeof(nums)/sizeof(int);	
        std::cout << "nums length is " << length << std::endl;

        sort(nums, nums + length, greater<int>());
        for (int i = 0; i < length; ++i){
            std::cout << nums[i] << "\t";	
        }
        std::cout << std::endl;
        sort(nums, nums + length, less<int>());
        for (int i = 0; i < length; ++i){
		        std::cout << nums[i] << "\t";	
        }
        std::cout << std::endl;
        return 0;
    }
    #endif

*/




