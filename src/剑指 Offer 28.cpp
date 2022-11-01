// id:373296127
// runtime:8 ms
// memory:16 MB
// title:对称的二叉树  LCOF
// translatedTitle:对称的二叉树
// questionId:100289
// time:2022-10-15 20:41:16

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool same(TreeNode*A,TreeNode*B){
        if(!A&&!B)return 1;
        if(!A||!B)return 0;
        if(A->val!=B->val)return 0;
        if(!same(A->left,B->right))return 0;
        if(!same(A->right,B->left))return 0;
        return 1;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return 1;
        return same(root->left,root->right);
    }
};