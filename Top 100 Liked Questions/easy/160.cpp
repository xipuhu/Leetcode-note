/* 原题内容
160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

 
begin to intersect at node c1.


Example 1:
 

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.


Example 2:

 
Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
Example 3:

 

Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/


// 第一遍解法代码
/* info:
*Runtime: 72 ms, faster than 15.78%
*Memory Usage: 23.6 MB, less than 5.10%
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;

    unordered_map<ListNode *, int> map_node;

    while (headA != NULL || headB != NULL){	
        if (headA != NULL){
            if (map_node.find(headA) != map_node.end())
                return headA;
            map_node.insert(make_pair(headA, headA->val));
            headA = headA->next;
        }
        if (headB != NULL){
            if (map_node.find(headB) != map_node.end())
                return headB;
            map_node.insert(make_pair(headB, headB->val));
            headB = headB->next;
        }

    }

    return NULL;
}

/* info:
*Runtime: 64 ms, faster than 26.97%
*Memory Usage: 20.2 MB, less than 6.81%
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;

    unordered_map<ListNode *, int> map_node;

    while (headA != NULL){
        map_node.insert(make_pair(headA, headA->val));
        headA = headA->next;
    }

    while (headB != NULL){
        if (map_node.find(headB) != map_node.end())
            return headB;
        headB = headB->next;
    }
    return NULL;
}

// 网上好的解法
/* info:
*Runtime: 52 ms, faster than 97.87%
*Memory Usage: 16.7 MB, less than 72.98%
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != pb) {
            pa = pa ? pa -> next : headB;
            pb = pb ? pb -> next : headA;
        }
        return pa;
}
/* info:
*Runtime: 52 ms, faster than 97.87%
*Memory Usage: 16.7 MB, less than 72.98%
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *pA = headA, *pB = headB;
        int lenA = 0, lenB = 0;
        while(pA) pA = pA->next, lenA++;
        while(pB) pB= pB->next, lenB++;
        pA = headA, pB = headB;
        if(lenA > lenB) for(int i = 0; i < lenA-lenB; ++i) pA = pA->next;
        else for(int i = 0; i < lenB-lenA; ++i) pB = pB->next;
        while(pA)
        {
            if(pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
}
// 精简优化
/* info:
*Runtime: 52 ms, faster than 97.87%
*Memory Usage: 16.8 MB, less than 39.36%
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
	
    int lenA = 0;
    int lenB = 0;
    ListNode * p = headA;

    while (p != NULL) ++lenA, p = p->next;
    p = headB;
    while (p != NULL) ++lenB, p = p->next;

    if (lenA > lenB){
        for (int i = 0; i < lenA - lenB; ++i)
            headA = headA->next;
    }
    else if (lenA < lenB){
        for (int i = 0; i < lenB - lenA; ++i)
            headB = headB->next;
    }

    while (headA != NULL && headB != NULL){
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}
/* 思考
1. 解法思路方面：

利用哈希表来存储一条list的指针，然后遍历另一条list来判断是否存在相同的指针

使用两个指针变量来交替遍历两个list，直到两者相遇（只有两种结果：NULL表示无交集，否则有交集并返回其中一个指针变量）

两个list的长度不一致的时候，比如lenA > lenB，则若两list存在交集，则交集必定在listA后lenB个节点中


2. 代码解决方面：

可以通过逗号来将两个短语句合在一块写。

使用ordered_map的时候要注意考虑空间效率。

*/




