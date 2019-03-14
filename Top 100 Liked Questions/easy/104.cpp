/* ԭ������
104. Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

// ��һ��ⷨ����
/* info:
*Runtime: 16 ms, faster than 99.11%
*Memory Usage: 19.6 MB, less than 22.11%
*/
int maxDepth(TreeNode* root) {
    if(root==NULL) return 0; 
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// ���ϺõĽⷨ
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/

// �����Ż�
/* info:
*Runtime: 16 ms, faster than 99.11%
*Memory Usage: 19.6 MB, less than 22.11%
*/
int maxDepth(TreeNode* root) {
    return root == NULL ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
}

/* ˼��
1. �ⷨ˼·���棺



2. ���������棺
*/




