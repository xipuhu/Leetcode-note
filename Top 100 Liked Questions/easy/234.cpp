/* 原题内容
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


// 第一遍解法代码
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

// 网上好的解法
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

// 精简优化
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/

/* 思考
1. 解法思路方面：

将整个list反转并存储为list2，然后同时遍历list和list2，如果两者值不相同则返回false，直到list和list2遍历结束后，返回true

通过一个慢指针(p=p->next)和快指针(p=p->next->next)来定位出list的中间结点，然后反转该中间结点后面剩余的list，
最后同时遍历这两半list来判断是否值都相等，不相等则返回false

2. 代码解决方面：

对于list中结点的反转：node->next->next = node

注意：在使用访问node->next->next的时候，一定要先判断node->next是否为nullptr！

*/




