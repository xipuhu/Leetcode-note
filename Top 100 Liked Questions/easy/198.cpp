/* 原题内容
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


// 第一遍解法代码
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
// 网上好的解法
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

// 精简优化
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
/* 思考
1. 解法思路方面：

动态规划（dp）：对于nums，我们可以在遍历的同时记录好目前nums[i]对应的能获得的最高金额，由于相邻的元素不能求和，因此需用利用dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])来计算。

动态规划小结：在计算下一个结果的时候需要参考上一次的结果，因此需要在遍历或迭代的过程中同时保存好“本次的结果”，以便作为下一次计算的参考值。至于怎样计算“本次的结果”，则需要依照题目所给的信息来确定。

2. 代码解决方面：

除了可以使用指针的形式来动态申请数组的大小，我们还可以使用vector<int> arr(n)来模拟动态大小数组的使用，在这里主要是借助了vector的构造函数来动态申请了n个整型变量。

关于优先队列priority_queue：优先级队列是一种容器适配器，根据一些严格的弱排序标准，专门设计使其第一个元素始终是它包含的最大元素。

priority_queue 模板有3个参数，其中两个有默认的参数；第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象默认是less，它定义了一个用来决定元素顺序的断言。因此模板类型是：
template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue

代码例子：
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
	    bool operator() (Node a, Node b){          //默认是less函数

		    //返回true时，a的优先级低于b的优先级（a排在b的后面）
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

greater 和less:在头文件<functional>里面，greater和less都重载了操作符
我们一般用sort函数的时候，greater和less可以作为函数指针传递下去，不需要单独写比较函数作为函数指针传递给sort函数的第三个参数
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




