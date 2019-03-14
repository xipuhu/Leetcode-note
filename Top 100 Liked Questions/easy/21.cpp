/* 原题内容
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

// 第一遍解法代码
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10.3 MB, less than 9.51%
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	ListNode* l = new ListNode(0);
	ListNode* l_tmp = l;

	if (l1 == NULL || l2 == NULL){
		if (l1 != NULL)
			return l1;
		else if (l2 != NULL)
			return l2;
		else
			return NULL;
	}

	while (l1 != NULL && l2 != NULL){

		ListNode* tmp = new ListNode(0);

		if (l1->val <= l2->val){
			tmp->val = l1->val;
			l_tmp->next = tmp;

			l1 = l1->next;
		}
		else{
			tmp->val = l2->val;
			l_tmp->next = tmp;
			l2 = l2->next;
		}

		l_tmp = l_tmp->next;
	}

	if (l1 != NULL)
		l_tmp->next = l1;
	else if (l2 != NULL)
		l_tmp->next = l2;
	return l->next;
}



// 网上好的解法
/* info
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //speed up
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;
        ListNode res(0);
        ListNode *curRes = &res;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val)
            {
                curRes->next = l1;
                l1 = l1->next;
            }else
            {
                curRes->next = l2;
                l2 = l2->next;
            }
            curRes = curRes->next;
        }
        curRes->next = l1 ? l1 : l2;
        return res.next;
    }
/*
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10.1 MB, less than 41.03%
*/
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if (!a || b && a->val > b->val) swap(a, b);
    if (a) a->next = mergeTwoLists(a->next, b);
    return a;
}

/*
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 9.9 MB, less than 87.68%
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }
    
    if(l2->val < l1->val)
    {
        swap(l1, l2);
    }
    ListNode dummy(0);
    dummy.next = l1;
    ListNode* prev = &dummy;
    while(l1)
    {
        if(l1->val > l2->val)
        {
            prev->next = l2;
            swap(l1, l2);
        }
        prev = l1;
        l1 = l1->next;
    }
    prev->next = l2;

    return dummy.next;
}


// 精简优化
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    ListNode* l3 = new ListNode(0);
    ListNode* l3_tmp = l3;

    while (l1 != NULL && l2 != NULL){

        if (l1->val < l2->val){
            l3_tmp->next = l1;
            l1 = l1->next;
        }
        else{        
            l3_tmp->next = l2;
            l2 = l2->next;
        }

        l3_tmp = l3_tmp->next;
    }

    l3_tmp->next = l1 ? l1 : l2;

    return l3->next;
}

/* 思考
1. 解法思路方面：

遍历l1和l2的过程中比较其值的大小，并同时用l3保存较小的结点；

遍历l1和l2的时候，使用默认的swap()函数来交换该两个结点


2. 代码解决方面：

//关于p->next的赋值问题：
ListNode* gg = new ListNode(0);

ListNode* gg_tmp = gg->next;

gg_tmp = new ListNode(2);

if (gg->next == NULL)    // 将会输出NULL
  cout << "NULL" << endl;

Swap()函数是可以默认使用的，不需要自己去定义，其交换的方式是值交换：
int a = 90, b = 20;
int* c = &a;
int* d = &b;

cout << "&c:" << &c << " " << "&d:" << &d << endl;
cout << "c:" << c << " " << "d:" << d << endl;swap(c, d);
cout << "&c:" << &c << " " << "&d:" << &d << endl;
cout << "c:" << c << " " << "d:" << d << endl;

输出结果如下：
&c:0034FABC &d:0034FAB0
c:0034FAD4 d:0034FAC8
&c:0034FABC &d:0034FAB0
c:0034FAC8 d:0034FAD4

NULL、0、nullptr的区别：

C的NULL：在C语言中，我们使用NULL表示空指针，实际上在C语言中，NULL通常被定义为如下：
#define NULL ((void *)0)

也就是说NULL实际上是一个void *的指针，然后把void *指针赋值给int *和foo_t *的指针的时候，隐式转换成相应的类型。而如果换做一个C++编译器来编译的话是要出错的，因为C++是强类型的，void *是不能隐式转换成其他指针类型的，所以通常情况下，编译器提供的头文件会这样定义NULL：
#ifdef __cplusplus ---简称：cpp c++ 文件
#define NULL 0
#else
#define NULL ((void *)0)
#endif

C++的0：因为C++中不能将void *类型的指针隐式转换成其他指针类型，而又为了解决空指针的问题，所以C++中引入0来表示空指针（注：0表示，还是有缺陷不完美），这样就有了类似上面的代码来定义NULL。实际上C++的书都会推荐说C++中更习惯使用0来表示空指针而不是NULL。

C++11的nullptr:虽然上面我们说明了0比NULL可以让我们更加警觉，但是我们并没有避免这个问题。这个时候C++ 11的nullptr就很好的解决了这个问题，我们在C++ 11中使用nullptr来表示空指针。如果使用 nullptr 初始化对象，就能避免 0 指针的二义性的问题。

*/



