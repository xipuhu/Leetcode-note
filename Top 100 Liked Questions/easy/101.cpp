/* ԭ������
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

// ��һ��ⷨ����
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

// ���ϺõĽⷨ
/* info:
*Runtime: 16 ms, faster than 41.18%
*Memory Usage: 15.7 MB, less than 90.61%
*/
// �ݹ�
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
// ����1
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
// ����2
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

// �����Ż�
/* info:
*Runtime: 12 ms, faster than 100.00%
*Memory Usage: 10 MB, less than 68.28%
*/


/* ˼��
1. �ⷨ˼·���棺

������ͨ��һ�����У��������ȡ���ҽ��ֵ���������˳��Ϊ-[p1->left, p2->right, p1->right, p2->left]������ǰ���������������ڽ��ֵ����������ȥ������ȥ��

�ݹ飺ͨ���۲����֪������������������Ϊ�����ʱ����һ����������������һ������һ������������������ͬ���������������������������һ������������������ͬ��ͨ��������������еݹ鴦��
    


2. ���������棺

�ж϶�����������㣨p1, p2����ֵ�Ƿ���ȵ�ʱ�򣬱��밴����˳�����:
if(p1 == NULL && p2 == NULL)   //�����ж�p1��p2�Ƿ���NULL
if(p1 == NULL || p2 == NULL)   //Ȼ���ж�p1��p2֮���Ƿ���һ��ΪNULL
if(p1->val == p2->val)         //����ж�p1��p2��ֵ�Ƿ���ȣ���ʱ�Ѿ�ȷ��p1��p2������NULL�ˣ�

����ʹ�ö�������ȡ���������Ľ�㣬�������԰��մ����һ��ߴ��ҵ����˳������ȡ�ӽ�㣬��֮ͨ�����п��ԶԶ��������в������

�ݹ�͵�����
1���ݹ����ظ����ú�������ʵ��ѭ��
2�������Ǻ�����ĳ�δ���ʵ��ѭ��
3����������ͨѭ���������ǣ�����ʱ�������в�������ı���ͬʱ�Ǳ������ı�������ǰ����Ľ����Ϊ��һ��ѭ������ĳ�ʼֵ��
*/







