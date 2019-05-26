/* 原题内容
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


// 第一遍解法代码
/* info:
*Runtime: 32 ms, faster than 97.61%
*Memory Usage: 24 MB, less than 52.23%
*/
//  利用搜索二叉树（排序二叉树）的特点：中序遍历的结果是从小到大有序的
//  用一个栈将其中序遍历的结果保存下来
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


// 网上好的解法
/* info:
*Runtime: 32 ms, faster than 97.61%
*Memory Usage: 23.7 MB, less than 56.01%
*/
// 从右子树开始中序遍历搜索二叉树，并在遍历的过程中求和（此时的求和为从大到小的求和）
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
// 精简优化
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/

/* 思考
1. 解法思路方面：

根据搜索二叉树（又名排序二叉树的特点），用一个栈来暂时保存其中序遍历的结果，然后对这个结果按题目要求对每一个
结点的val值进行处理。

采用递归对搜索二叉树进行中序遍历，并在遍历的过程中对每一个结点的val进行求和，求和的中间结果是从大到小排序的。
注意：此时的中序遍历并不是从左子树开始遍历的，而是从右子树开始遍历的，这样的目的就是将从小到大的中序遍历结果顺序逆过来。

2. 代码解决方面：

*/




