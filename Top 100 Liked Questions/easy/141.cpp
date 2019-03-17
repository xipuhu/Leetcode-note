/* ԭ������
141. Linked List Cycle
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

 

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.

 

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

 

*/

// ��һ��ⷨ����
/* info:
*Runtime: 12 ms, faster than 99.69%
*Memory Usage: 9.5 MB, less than 98.30%
*/
bool hasCycle(ListNode *head) {

    if (head == NULL || head->next == NULL) return false;

    ListNode *p1 = head->next;
    ListNode *p2 = head->next->next;

    while (p1 != NULL && p2 != NULL){
		
        if (p1 == p2) return true;

        if (p2->next != NULL)
            p2 = p2->next->next;
        else
            return false;
        p1 = p1->next;
    }
    return false;
}

/* info:
*Runtime: 20 ms, faster than 25.40%
*Memory Usage: 12.2 MB, less than 5.09%
*/
bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode *p = head;
    unordered_map<ListNode*, int> pointer_map;

    while (p != NULL){
        if (pointer_map.find(p) != pointer_map.end())
            return true;
        pointer_map.insert(make_pair(p, p->val));
        p = p->next;
    }
    return false;
}


// ���ϺõĽⷨ
/* info:
*Runtime: 12 ms, faster than 99.69%
*Memory Usage: 9.6 MB, less than 97.55%
*/
bool hasCycle(ListNode *head) {
    auto one = head, two = head;
    while(two && two->next){
        one = one->next;
        two = two->next->next;
        if(one == two) return true;
    }
    return false;
}

/* info:
*Runtime: 12 ms, faster than 99.69%
*Memory Usage: 9.9 MB, less than 15..09%
*/
bool hasCycle(ListNode *head) {
    if(head==NULL) return false;
    if(head->val==-1&&head->next->val==-1) return true;
    head->val=-1;
    return hasCycle(head->next);
}
// �����Ż�
/* info:
*Runtime: 12 ms, faster than 99.69%
*Memory Usage: 9.8 MB, less than 52.83%
*/
bool hasCycle(ListNode *head) {

    if (head == NULL || head->next == NULL) return false;

    ListNode *p1 = head->next;
    ListNode *p2 = head->next->next;

    while (p1 != NULL && p2 != NULL && p2->next != NULL){	
        if (p1 == p2) return true;
        p1 = p1->next;
        p2 = p2->next;
    }
    return false;
}

/* ˼��
1. �ⷨ˼·���棺

��ϣ�����ù�ϣ���¼ÿ�α�����ָ���㣬ͬʱ�жϸñ�������ָ�����Ƿ��Ѿ������ڹ�ϣ���У����������Ǻ��л�

ʹ��һ���ƶ�������ָ���һ���ƶ��Ŀ��ָ��ͬʱ��������ָ���б���������ʱ��������ָ������ˣ�����ڻ���


2. ���������棺

�ڷ���p->next��ʱ��һ��Ҫ���ж�p�Ƿ�ΪNULL��

*/




