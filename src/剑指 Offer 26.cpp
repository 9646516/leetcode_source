// id:373294949
// runtime:40 ms
// memory:32.7 MB
// title:树的子结构  LCOF
// translatedTitle:树的子结构
// questionId:100287
// time:2022-10-15 20:37:07

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
    bool cmp(TreeNode*A,TreeNode*B){
        if(!B)return 1;
        if(A->val!=B->val)return 0;
        if(B->left){
            if(!A->left)return 0;
            if(!cmp(A->left,B->left))return 0;
        }
        if(B->right){
            if(!A->right)return 0;
            if(!cmp(A->right,B->right))return 0;
        }
        return 1;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B)return 0;
        if(isSubStructure(A->left,B))return 1;
        if(isSubStructure(A->right,B))return 1;
        if(cmp(A,B))return 1;
        return 0;
    }
};