/* 原题内容
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/


// 第一遍解法代码
/* info:
*Runtime: 36 ms, faster than 87.06%
*Memory Usage: 17 MB, less than 55.38%
*/
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> min_stack;

    MinStack(){
        min_stack.push_back(INT_MAX);
    }
    void push(int x){
        stack.push_back(x);
        if (x <= min_stack[min_stack.size() - 1])
            min_stack.push_back(x);
    }
    void pop(){
        if (top() == min_stack[min_stack.size() - 1])
            min_stack.pop_back();
        stack.pop_back();
    }
    int top(){
        return stack[stack.size() - 1];
    }
    int getMin(){
        return min_stack[min_stack.size() - 1];
    }
};


// 网上好的解法
/* info:
*Runtime: 36 ms, faster than 87.06%
*Memory Usage: 17 MB, less than 62.10%
*/
public:
    stack<int> s;
    stack<int> minStack;
    
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if (minStack.top() == s.top())
            minStack.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/* info:
*Runtime: 36 ms, faster than 87.06%
*Memory Usage: 17 MB, less than 62.10%
*/
class MinStack {
private: 
    stack<pair<int,int>> s;       // pair of (value, current min)
public:
    MinStack() { }
    void push(int x) { s.emplace(x, min(getMin(), x)); }
    void pop() { if (!s.empty()) s.pop(); }
    int top() { return s.top().first; }
    int getMin() { return s.empty()? INT_MAX : s.top().second; }
};

/* info:
*Runtime: 36 ms, faster than 87.06%
*Memory Usage: 17 MB, less than 42.20%
*/
class MinStack {
private:
    vector<int> data;
    vector<int> minHist;

public:
void push(int x) {
    data.push_back(x);
    if (minHist.empty()) minHist.push_back(x);
    else minHist.push_back(min(minHist.back(),x)); 
}

void pop() {
    data.pop_back();
    minHist.pop_back();
}

int top() {
    return data.back();
}

int getMin() {
    return minHist.back();
}
};

// 精简优化
/* info:
*Runtime: 36 ms, faster than 87.06%
*Memory Usage: 16.9 MB, less than 78.49%
*/
class MinStack
{
public:
    vector<int> stack;
    vector<int> min_stack;

    MinStack(){
        min_stack.push_back(INT_MAX);
    }
    void push(int x){
        stack.emplace_back(x);
        if (x <= min_stack.back())
            min_stack.emplace_back(x);
    }
    void pop(){
        if (top() == min_stack.back())
            min_stack.pop_back();
        stack.pop_back();
    }
    int top(){
        return stack.back();
    }
    int getMin(){
        return min_stack.back();
    }

private:

};

/* 思考
1. 解法思路方面：

分别使用两个stack或vector分别存储当前栈中的元素以及栈中最小的值

使用一个pair变量分别存储当前要push的元素值和栈中当前最小值

2. 代码解决方面：

vector有一个back()函数等价于v[v.size()-1]

C++优化之使用emplace: 在C++开发过程中，我们经常会用STL的各种容器，比如vector，map，set等，这些容器极大的方便了我们的开发。在使用这些容器的过程中，我们会大量用到的操作就是插入操作，比如vector的push_back，map的insert，set的insert。这些插入操作会涉及到两次构造，首先是对象的初始化构造，接着在插入的时候会复制一次，会触发拷贝构造。但是很多时候我们并不需要两次构造带来效率的浪费，如果可以在插入的时候直接构造，就只需要构造一次就够了。
    因此在C++11中，针对顺序容器(如vector、deque、list)，新标准引入了三个新成员：emplace_front、emplace和emplace_back，这些操作构造而不是拷贝元素。这些操作分别对应push_front、insert和push_back，允许我们将元素放置在容器头部、一个指定位置之前或容器尾部。

*/




