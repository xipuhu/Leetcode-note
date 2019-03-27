/* ԭ������
226. Invert Binary Tree
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can��t invert a binary tree on a whiteboard so f*** off.

*/


// ��һ��ⷨ����
/* info:
*Runtime: 4 ms, faster than 100.00%
*Memory Usage: 9.2 MB, less than 57.67%
*/
TreeNode* invertTree(TreeNode* root) {

    if (root == NULL) return NULL;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// ���ϺõĽⷨ
/* info:
*Runtime: 4 ms, faster than 100.00%
*Memory Usage: 9 MB, less than 94.17%
*/
TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode *> tbpNode;
    if(root) tbpNode.push(root);
    TreeNode *curNode, *temp;

    while(!tbpNode.empty()){
        curNode = tbpNode.front();
        tbpNode.pop();
        temp = curNode->left;
        curNode->left = curNode->right;
        curNode->right = temp;
        if(curNode->left) tbpNode.push(curNode->left);
        if(curNode->right) tbpNode.push(curNode->right);
    }
    return root;
}
// �����Ż�
/* info:
*Runtime: 4 ms, faster than 100.00%
*Memory Usage: 9.1 MB, less than 66.57%
*/
TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            if(temp){
                st.push(temp->left);
                st.push(temp->right);
                swap(temp->left, temp->right);    // swap()����Ĭ��ʹ��
            }
        }
        return root;
}
/* ˼��
1. �ⷨ˼·���棺

�ݹ飺�ݹ������������㣬���Ȱѵ�ǰ�������ҽ�㽻���£�Ȼ��ݹ�ý���µ���������

�ǵݹ飺����һ��queue���洢��㣨�ý��������ӽ����δ����������ɸý������ҽ�㽻���󣬽����queue��ɾ��������Ӧ�����ҽ�����queue�У�Ȼ������ظ��ò��裬ֱ��queueΪ�ա�

2. ���������棺

swap()�����ǿ��Խ�������ָ��ģ���Ȼswap()���õ���ֵ������ʽ������ָ��Ҳ��һ��ֵ��

*/




