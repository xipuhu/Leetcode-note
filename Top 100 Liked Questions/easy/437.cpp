/* ԭ������
437. Path Sum III
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

*/


// ��һ��ⷨ����
/* info:
*Runtime: 28 ms, faster than 74.09%
*Memory Usage: 14.7 MB, less than 100.00%
*/
int pathSum_child(TreeNode* root, int sum, int currentSum){
    if (root == nullptr) return 0;       // �ڶ�root->left��root->right����֮ǰ����Ҫ�ж�root�Ƿ�Ϊnull

    currentSum += root->val;
    int left = pathSum_child(root->left, sum, currentSum);
    int right = pathSum_child(root->right, sum, currentSum);

    if (currentSum == sum)
        return left + right + 1;
    else
        return left + right;
}
int pathSum(TreeNode* root, int sum) {

    if (root == nullptr) return 0;    // �ڶ�root->left��root->right����֮ǰ����Ҫ�ж�root�Ƿ�Ϊnull

    int count = 0;
    int currentSum = 0;
    count += pathSum_child(root, sum, currentSum);

    return count + pathSum(root->left, sum) + pathSum(root->right, sum);    // �ݹ���������Ӷ������з��������·����

}
// ���ϺõĽⷨ
/* info:
*Runtime: 16 ms, faster than 100.00%
*Memory Usage: 14.6 MB, less than 100.00%
*/
vector<int> s;
int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        s.push_back(root->val);   // vectorҲ��push_back()����                    
        int count = pathSum(root->left, sum) + pathSum(root->right, sum);
        int tmp_sum = 0;
        for(int i = s.size()-1 ; i >= 0 ; i--) {
            tmp_sum += s[i];
            if (tmp_sum == sum) count++;
        }
        s.pop_back();
        return count;
}

/* info:
*Runtime: 28 ms, faster than 74.09%
*Memory Usage: 14.8 MB, less than 100.00%
*/
int pathSumAux(TreeNode* root, int sum,int cur){
        if(root==NULL)
            return 0;
        else if(root->val+cur==sum)
            return 1+pathSumAux(root->left,sum,root->val+cur)+pathSumAux(root->right,sum,root->val+cur);
        else
            return pathSumAux(root->left,sum,root->val+cur)+pathSumAux(root->right,sum,root->val+cur);
}

int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        return pathSumAux(root,sum,0)+pathSum(root->left,sum)+pathSum(root->right,sum);
}

// �����Ż�
/* info:
*Runtime: 28 ms, faster than 74.09%
*Memory Usage: 14.8 MB, less than 100.00%
*/
int pathSum(TreeNode* root, int sum) {
        return root ? f(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;
 }
    
int f(TreeNode* root, int sum) {
        return root ? (root->val == sum) + f(root->left, sum - root->val) + f(root->right, sum - root->val) : 0;
 } 



/* ˼��
1. �ⷨ˼·���棺

�ݹ飺���ҳ�root�������������з���������·�����������ܺ��ж��������ٵݹ���������Ӷ������з��������·����


2. ���������棺

�ڶ�root->left��root->right����֮ǰ����Ҫ�ж�root�Ƿ�Ϊnull�����ڼ����ݹ�֮ǰ����Ҫ�иò�������Ϊ�ݹ����������


*/




