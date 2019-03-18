/* ԭ������
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


// ��һ��ⷨ����
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


// ���ϺõĽⷨ
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

// �����Ż�
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

/* ˼��
1. �ⷨ˼·���棺

�ֱ�ʹ������stack��vector�ֱ�洢��ǰջ�е�Ԫ���Լ�ջ����С��ֵ

ʹ��һ��pair�����ֱ�洢��ǰҪpush��Ԫ��ֵ��ջ�е�ǰ��Сֵ

2. ���������棺

vector��һ��back()�����ȼ���v[v.size()-1]

C++�Ż�֮ʹ��emplace: ��C++���������У����Ǿ�������STL�ĸ�������������vector��map��set�ȣ���Щ��������ķ��������ǵĿ�������ʹ����Щ�����Ĺ����У����ǻ�����õ��Ĳ������ǲ������������vector��push_back��map��insert��set��insert����Щ����������漰�����ι��죬�����Ƕ���ĳ�ʼ�����죬�����ڲ����ʱ��Ḵ��һ�Σ��ᴥ���������졣���Ǻܶ�ʱ�����ǲ�����Ҫ���ι������Ч�ʵ��˷ѣ���������ڲ����ʱ��ֱ�ӹ��죬��ֻ��Ҫ����һ�ξ͹��ˡ�
    �����C++11�У����˳������(��vector��deque��list)���±�׼�����������³�Ա��emplace_front��emplace��emplace_back����Щ������������ǿ���Ԫ�ء���Щ�����ֱ��Ӧpush_front��insert��push_back���������ǽ�Ԫ�ط���������ͷ����һ��ָ��λ��֮ǰ������β����

*/




