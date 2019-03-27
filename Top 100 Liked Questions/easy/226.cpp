/* 原题内容
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

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

*/


// 第一遍解法代码
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

// 网上好的解法
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
// 精简优化
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
                swap(temp->left, temp->right);    // swap()可以默认使用
            }
        }
        return root;
}
/* 思考
1. 解法思路方面：

递归：递归遍历二叉树结点，首先把当前结点的左右结点交换下，然后递归该结点下的左右子树

非递归：利用一个queue来存储结点（该结点的左右子结点尚未交换），完成该结点的左右结点交换后，将其从queue中删除并将相应的左右结点存入queue中，然后继续重复该步骤，直到queue为空。

2. 代码解决方面：

swap()函数是可以交换两个指针的（虽然swap()才用的是值交换方式，但是指针也是一种值）

*/




