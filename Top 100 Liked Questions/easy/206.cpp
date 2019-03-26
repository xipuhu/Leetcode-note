/* ԭ������
206. Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/


// ��һ��ⷨ����
/* info:
*Runtime: 8 ms, faster than 100.00%
*Memory Usage: 9.1 MB, less than 74.07%
*/
ListNode* reverseList(ListNode* head) {

    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    stack<ListNode *> nodes;
    ListNode *p = head;
    ListNode *h = NULL;

    while (p != NULL){
        ListNode *tmp = p;
        nodes.push(tmp);

        p = p->next;
        tmp->next = NULL;
    }

    h = nodes.top();
    p = h;
    nodes.pop();

    while (!nodes.empty()){
        p->next = nodes.top();
        p = p->next;
        nodes.pop();
    }
    return h;
}
/* info:
*Runtime: 8 ms, faster than 100.00%
*Memory Usage: 8.9 MB, less than 99.44%
*/
ListNode* reverseList(ListNode* head) {

    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    ListNode *p1 = NULL;
    ListNode *p2 = head;

	
    head = head->next;
    p2->next = NULL;

    while (head != NULL){
        p1 = head;
        head = head->next;  // ��ʱp1�Ϳ��Ժ�ʣ���list���뿪��

        p1->next = p2;
        p2 = p1;

    }

    return p2;

}

// ���ϺõĽⷨ
/* info:
*Runtime: 8 ms, faster than 100.00%
*Memory Usage: 9.1 MB, less than 85.68%
*/
// ����
ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
}

/* info:
*Runtime: 8 ms, faster than 100.00%
*Memory Usage: 9.2 MB, less than 28.52%
*/
// �ݹ�
ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
}

// �����Ż�
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *p = reverseList(head->next);  // ��ִ����һ���󣬾Ͳ��������head�Ĳ�����Ӱ��ʣ��list��

    head->next->next = head;
    head->next = NULL;

    return p;

}

/* ˼��
1. �ⷨ˼·���棺

�ڵ���list�Ĺ����У����ú÷��뵱ǰ����ʣ��list�ļ��ɣ��Ϳ��Ժ����׵�ʵ��list��ת

�ݹ�˼�룺��ǰ���Ϊn_k������list��ʣ�ಿ�֣�n_k+1�������Ѿ��Ƿ�ת�õ�list�������ʹ��n_k->next->next = n_k����ʵ��n_k+1 -> next = n_k;

2. ���������棺

���ڵ�������list�еĽ���ʱ��һ��Ҫ����ȫ���ý���list�з��������ע�⣬�ڵ�һ��ⷨ�����У�ʹ��stack������洢����ʱ�����û�н������ȫ��������Ļ�����ôlist����û�䣬����ķſ���ʹ��node->next = NULL��ʵ�֡�

*/




