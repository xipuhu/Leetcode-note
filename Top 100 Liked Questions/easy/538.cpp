/* ԭ������
538. Convert BST to Greater Tree

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this
             18
            /   \
          20     13
*/


// ��һ��ⷨ����
/* info:
*Runtime: 32 ms, faster than 97.61%
*Memory Usage: 24 MB, less than 52.23%
*/
//  ������������������������������ص㣺��������Ľ���Ǵ�С���������
//  ��һ��ջ������������Ľ����������
stack<TreeNode*> s;
void inoder_BST(TreeNode* root){
    if (root != nullptr){
        inoder_BST(root->left);
        s.push(root);
        inoder_BST(root->right);
    }
}
TreeNode* convertBST(TreeNode* root) {
	
    int sum = 0;
    inoder_BST(root);

    while (!s.empty()){
        sum += s.top()->val;
        s.top()->val = sum;
        s.pop();
    }
    return root;
}


// ���ϺõĽⷨ
/* info:
*Runtime: 32 ms, faster than 97.61%
*Memory Usage: 23.7 MB, less than 56.01%
*/
// ����������ʼ����������������������ڱ����Ĺ�������ͣ���ʱ�����Ϊ�Ӵ�С����ͣ�
int sum = 0;
TreeNode* convertBST(TreeNode* root) {
    if (root != nullptr){
        convertBST(root->right);     
        sum += root->val;
        root->val = sum;
        convertBST(root->left);     
    }
    return root;
}
// �����Ż�
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/

/* ˼��
1. �ⷨ˼·���棺

��������������������������������ص㣩����һ��ջ����ʱ��������������Ľ����Ȼ�������������ĿҪ���ÿһ��
����valֵ���д���

���õݹ����������������������������ڱ����Ĺ����ж�ÿһ������val������ͣ���͵��м����ǴӴ�С����ġ�
ע�⣺��ʱ��������������Ǵ���������ʼ�����ģ����Ǵ���������ʼ�����ģ�������Ŀ�ľ��ǽ���С���������������˳���������

2. ���������棺

*/




