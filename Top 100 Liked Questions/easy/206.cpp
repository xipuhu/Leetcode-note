/* 原题内容
206. Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/


// 第一遍解法代码
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
        head = head->next;  // 此时p1就可以和剩余的list脱离开了

        p1->next = p2;
        p2 = p1;

    }

    return p2;

}

// 网上好的解法
/* info:
*Runtime: 8 ms, faster than 100.00%
*Memory Usage: 9.1 MB, less than 85.68%
*/
// 迭代
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
// 递归
ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
}

// 精简优化
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *p = reverseList(head->next);  // 先执行这一步后，就不用下面对head的操作会影响剩余list了

    head->next->next = head;
    head->next = NULL;

    return p;

}

/* 思考
1. 解法思路方面：

在迭代list的过程中，利用好分离当前结点和剩余list的技巧，就可以很容易的实现list反转

递归思想：当前结点为n_k，假设list的剩余部分（n_k+1…）都已经是反转好的list，则可以使用n_k->next->next = n_k，来实现n_k+1 -> next = n_k;

2. 代码解决方面：

对于单独处理list中的结点的时候，一定要先完全将该结点从list中分离出来。注意，在第一遍解法代码中，使用stack来另外存储结点的时候，如果没有将结点完全分离从来的话，那么list依旧没变，分离的放可以使用node->next = NULL来实现。

*/




