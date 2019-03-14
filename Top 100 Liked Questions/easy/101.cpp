/* 原题内容
101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
    1
   / \ 
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

// 第一遍解法代码
/* info:
*Runtime:  ms, faster than %
*Memory Usage:  MB, less than %
*/
vector<int> results;
void InOrder(TreeNode* T){
    if (T != NULL){
        InOrder(T->left);
        results.push_back(T->val);
        InOrder(T->right);
    }
    else
        results.push_back(NULL);
}
bool isSymmetric(TreeNode* root) {

    InOrder(root);
    int len = results.size();

    int mid = len / 2;
    int left = mid - 1, right = mid + 1;
    while (left >= 0 && right < len){
        if (results[left--] != results[right++])
            return false;
    }
    return true;
}

// 网上好的解法
/* info:
*Runtime: 16 ms, faster than 41.18%
*Memory Usage: 15.7 MB, less than 90.61%
*/
// 递归
bool isMirror(TreeNode* T1, TreeNode* T2){

    if (T1 == NULL && T2 == NULL) return true;
    if (T1 == NULL || T2 == NULL) return false;

    return (T1->val == T2->val)  && isMirror(T1->left, T2->right) && isMirror(T1->right, T2->left);

}

bool isSymmetric(TreeNode* root) {

    return isMirror(root, root);
}

/* info:
*Runtime: 12 ms, faster than 97.13%
*Memory Usage: 16.1 MB, less than 19.86%
*/
// 迭代1
bool isSymmetric(TreeNode* root){
    queue<TreeNode* > q;
	
    q.push(root);
    q.push(root);
	
    while (!q.empty()){
        TreeNode* q1 = q.front();
        q.pop();
        TreeNode* q2 = q.front();
        q.pop();

        if (q1 == NULL && q2 == NULL) continue;
        if (q1 == NULL || q2 == NULL) return false;
        if (q1->val != q2->val) return false;

        q.push(q1->left);
        q.push(q2->right);
        q.push(q1->right);
        q.push(q2->left);
    }

    return true;

}

/* info:
*Runtime: 12 ms, faster than 97.13%
*Memory Usage: 15.9 MB, less than 63.54%
*/
// 迭代2
bool isSymmetric(TreeNode* root){
    queue<TreeNode* > q;
	
    q.push(root);
    q.push(root);

    TreeNode* q1;
    TreeNode* q2;	
    while (!q.empty()){
        q1 = q.front();
        q.pop();
        q2 = q.front();
        q.pop();

        if (q1 == NULL && q2 == NULL) continue;
        if (q1 == NULL || q2 == NULL) return false;
        if (q1->val != q2->val) return false;

        q.push(q1->left);
        q.push(q2->right);
        q.push(q1->right);
        q.push(q2->left);
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

迭代：通过一个队列，来交替读取左右结点值，即保存的顺序为-[p1->left, p2->right, p1->right, p2->left]，当最前面两个连续的相邻结点值相等则继续下去迭代下去。

递归：通过观察可以知道，当两个二叉树互为镜像的时候，则一个二叉树的左子树一定和另一个二叉树的右子树相同，并且这个二叉树的右子树和另一个二叉树的左子树相同。通过这个现象来进行递归处理：
    


2. 代码解决方面：

判断二叉树两个结点（p1, p2）的值是否相等的时候，必须按如下顺序进行:
if(p1 == NULL && p2 == NULL)   //首先判断p1和p2是否都是NULL
if(p1 == NULL || p2 == NULL)   //然后判断p1和p2之中是否有一个为NULL
if(p1->val == p2->val)         //最后判断p1和p2的值是否相等（此时已经确保p1和p2都不是NULL了）

可是使用队列来读取左右子树的结点，这样可以按照从左到右或者从右到左的顺序来读取子结点，总之通过队列可以对二叉树进行层遍历。

递归和迭代：
1）递归是重复调用函数自身实现循环
2）迭代是函数内某段代码实现循环
3）迭代和普通循环的区别是：迭代时，代码中参与运算的变量同时是保存结果的变量，当前保存的结果作为下一次循环计算的初始值。
*/







