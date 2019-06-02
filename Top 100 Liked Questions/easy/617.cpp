/* ԭ������
617. Merge Two Binary Trees

Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
 
Note: The merging process must start from the root nodes of both trees.

*/


// ��һ��ⷨ����
/* info:
*Runtime: 36 ms, faster than 95.57%
*Memory Usage: 14.7 MB, less than 57.78%
*/
// ͬ���������t1��t2������ǰ���ĸ��ڵ㣨p1��p2��������Ϊ�˿��Խ�t2�д��ڵĽ�����ӵ�t1�е�ǰ�����ڽ���λ���ϡ�
void merge(TreeNode* t1, TreeNode* t2, TreeNode* p1, TreeNode* p2){

    if (t1 != nullptr){
        if (t2 != nullptr){
            t1->val += t2->val;
            merge(t1->left, t2->left, t1, t2);
            merge(t1->right, t2->right, t1, t2);
        }	
    }
    else{
        if (t2 != nullptr){
            TreeNode* tmp = new TreeNode(t2->val);
			
            if (p2->left == t2){
                p1->left = tmp;
                merge(p1->left->left, t2->left, p1->left, t2);
                merge(p1->left->right, t2->right, p1->left, t2);
            }
            else{
                p1->right = tmp;
                merge(p1->right->left, t2->left, p1->right, t2);
                merge(p1->right->right, t2->right, p1->right, t2);
            }
        }
    }

}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

    if (t1 == nullptr && t2 == nullptr) return nullptr;
    if (t1 == nullptr || t2 == nullptr) return (t1 != nullptr ? t1 : t2);

    merge(t1, t2, t1, t2);

    return t1;
}
// ���ϺõĽⷨ
/* info:
*Runtime: 40 ms, faster than 95.57%
*Memory Usage: 13.6 MB, less than 77.31%
*/
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

    if(t1 == nullptr) return t2;
    if(t2 == nullptr) return t1;
    
    t1->val += t2->val;
    
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}
// �����Ż�
/* info:
*Runtime: 0 ms, faster than 0%
*Memory Usage: 0 MB, less than 0%
*/

/* ˼��
1. �ⷨ˼·���棺

    a. ͬʱ��ͬ���������t1��t2�������ڱ����Ĺ����а���ĿҪ�����t1�еĽ�㣨���յĽ��������t1�У�������t1��

2. ���������棺
    
    a. ���ڸ�����һ������ʱ���������������Ҫע�⣬���Ǳ������һ������p->next��ֵ����ֵΪnull���������Ǳ�����p->next�����㣨����tmp=p->next��ֵΪnull�������������ͨ������tmp��ֵ������p->next����������������������������
		struct Test{

			int val;
			Test* next;

			Test(int v) : val(v), next(nullptr){}
		};

		int main(){

			Test* t = new Test(1);
			Test* t2 = new Test(2);

			Test* tmp = t;

			while (tmp != nullptr){
			    tmp = tmp->next;
			}

			tmp = t2;
            
            // ������Ϊ��1
			while (t != nullptr){
			    cout << t->val << " ";
			    t = t->next;
			}
			return 0;
		}
*/




