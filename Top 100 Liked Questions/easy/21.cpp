/* ԭ������
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

// ��һ��ⷨ����
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



// ���ϺõĽⷨ
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


// �����Ż�
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

/* ˼��
1. �ⷨ˼·���棺

����l1��l2�Ĺ����бȽ���ֵ�Ĵ�С����ͬʱ��l3�����С�Ľ�㣻

����l1��l2��ʱ��ʹ��Ĭ�ϵ�swap()�������������������


2. ���������棺

//����p->next�ĸ�ֵ���⣺
ListNode* gg = new ListNode(0);

ListNode* gg_tmp = gg->next;

gg_tmp = new ListNode(2);

if (gg->next == NULL)    // �������NULL
  cout << "NULL" << endl;

Swap()�����ǿ���Ĭ��ʹ�õģ�����Ҫ�Լ�ȥ���壬�佻���ķ�ʽ��ֵ������
int a = 90, b = 20;
int* c = &a;
int* d = &b;

cout << "&c:" << &c << " " << "&d:" << &d << endl;
cout << "c:" << c << " " << "d:" << d << endl;swap(c, d);
cout << "&c:" << &c << " " << "&d:" << &d << endl;
cout << "c:" << c << " " << "d:" << d << endl;

���������£�
&c:0034FABC &d:0034FAB0
c:0034FAD4 d:0034FAC8
&c:0034FABC &d:0034FAB0
c:0034FAC8 d:0034FAD4

NULL��0��nullptr������

C��NULL����C�����У�����ʹ��NULL��ʾ��ָ�룬ʵ������C�����У�NULLͨ��������Ϊ���£�
#define NULL ((void *)0)

Ҳ����˵NULLʵ������һ��void *��ָ�룬Ȼ���void *ָ�븳ֵ��int *��foo_t *��ָ���ʱ����ʽת������Ӧ�����͡����������һ��C++������������Ļ���Ҫ����ģ���ΪC++��ǿ���͵ģ�void *�ǲ�����ʽת��������ָ�����͵ģ�����ͨ������£��������ṩ��ͷ�ļ�����������NULL��
#ifdef __cplusplus ---��ƣ�cpp c++ �ļ�
#define NULL 0
#else
#define NULL ((void *)0)
#endif

C++��0����ΪC++�в��ܽ�void *���͵�ָ����ʽת��������ָ�����ͣ�����Ϊ�˽����ָ������⣬����C++������0����ʾ��ָ�루ע��0��ʾ��������ȱ�ݲ���������������������������Ĵ���������NULL��ʵ����C++���鶼���Ƽ�˵C++�и�ϰ��ʹ��0����ʾ��ָ�������NULL��

C++11��nullptr:��Ȼ��������˵����0��NULL���������Ǹ��Ӿ������������ǲ�û�б���������⡣���ʱ��C++ 11��nullptr�ͺܺõĽ����������⣬������C++ 11��ʹ��nullptr����ʾ��ָ�롣���ʹ�� nullptr ��ʼ�����󣬾��ܱ��� 0 ָ��Ķ����Ե����⡣

*/



