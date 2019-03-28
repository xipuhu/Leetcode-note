/* ԭ������
234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

*/


// ��һ��ⷨ����
/* info:
*Runtime: 32 ms, faster than 21.28%
*Memory Usage: 14.5 MB, less than 5.09%
*/
bool isPalindrome(ListNode* head) {

    if (head == nullptr || head->next == nullptr) return true;
	
    ListNode* p = head;
	
    ListNode* last = nullptr;

    while(p != nullptr){
		
        ListNode* tmp = new ListNode(0);

        tmp->val = p->val;
        tmp->next = last;
        last = tmp;
        p = p->next;
    }

    while (head != nullptr && last != nullptr){
        if (head->val != last->val)
            return false;

        head = head->next;
        last = last->next;
    }

    return true;
}

// ���ϺõĽⷨ
/* info:
*Runtime: 24 ms, faster than 97.94%
*Memory Usage: 12.5 MB, less than 78.55%
*/
bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;
        ListNode* mid=head,*end=head,*prev=NULL,*next=mid;
        while(end && end->next)
        {
            mid=mid->next;
            end=end->next->next;
        }
        while(next)
        {
            next=mid->next;
            mid->next=prev;
            prev=mid;
            mid=next;
        }
        while(prev && head)
        {
            if(head->val!=prev->val)return false;
            prev=prev->next;head=head->next;
        }
        return true;
}

// �����Ż�
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/

/* ˼��
1. �ⷨ˼·���棺

������list��ת���洢Ϊlist2��Ȼ��ͬʱ����list��list2���������ֵ����ͬ�򷵻�false��ֱ��list��list2���������󣬷���true

ͨ��һ����ָ��(p=p->next)�Ϳ�ָ��(p=p->next->next)����λ��list���м��㣬Ȼ��ת���м������ʣ���list��
���ͬʱ����������list���ж��Ƿ�ֵ����ȣ�������򷵻�false

2. ���������棺

����list�н��ķ�ת��node->next->next = node

ע�⣺��ʹ�÷���node->next->next��ʱ��һ��Ҫ���ж�node->next�Ƿ�Ϊnullptr��

*/




