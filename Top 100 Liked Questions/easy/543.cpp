/* ԭ������

543. Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/


// ��һ��ⷨ����
/* info:
*Runtime: 44 ms, faster than 5.78%
*Memory Usage: 35.5 MB, less than 5.03%
*/
// ��ÿ���ڵ��������������ȣ����ߵĺͼ�Ϊ�ýڵ�����·���������
int max_depth(TreeNode* root){
	
    if (root == nullptr)
        return 0;

    return 1 + max(max_depth(root->left), max_depth(root->right));

}
int max_diameter = 0;
int diameterOfBinaryTree(TreeNode* root){
    if (root != nullptr){
        root->val = max_depth(root->left) + max_depth(root->right);
        max_diameter = max(max_diameter, root->val);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
    }

    return max_diameter;
}
// ���ϺõĽⷨ
/* info:
*Runtime: 8 ms, faster than 98.55%
*Memory Usage: 20 MB, less than 61.38%
*/
//  6-liner C++ Post-order traversal�����������
    int maxLen = 0;
    
    int diameterOfBinaryTree(TreeNode* r) {
        return maxDown(r), maxLen;
    }
    
    int maxDown(TreeNode* x) {
        if (!x) return 0;
        int maxL = maxDown(x->left), maxR = maxDown(x->right);
        maxLen = max(maxLen, maxL + maxR);
        return max(maxL, maxR) + 1;        
    } 
// �����Ż�
/* info:
*Runtime: 8 ms, faster than 98.55%
*Memory Usage: 20 MB, less than 57.90%
*/
//  ��������������ȵ�ͬʱ����¼���·���ĳ��ȣ��������Լ���һ�ζԶ������ĵݹ�������Ӷ�����ٶ�
int ans = 0;
int depth(TreeNode* root){

    if (root == nullptr)
        return 0;
	
    int L = depth(root->left);
    int R = depth(root->right);
    ans = max(ans, L + R);

    return 1 + max(L, R);
}
int diameterOfBinaryTree(TreeNode* root){
    depth(root);
    return ans;
}

/* ˼��
1. �ⷨ˼·���棺

�ֱ���ÿ���ڵ��������������ȣ�L��R�������ߵĺͣ�L+R����Ϊ�ýڵ�����·���������

2. ���������棺

*/




