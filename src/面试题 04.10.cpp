// id:374558993
// runtime:44 ms
// memory:39.3 MB
// title:Check SubTree LCCI
// translatedTitle:检查子树
// questionId:100229
// time:2022-10-19 17:41:16

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
    bool same(TreeNode*t1,TreeNode*t2){
        if(!t1&&!t2)return 1;
        if(!t1||!t2)return 0;
        if(t1->val!=t2->val)return 0;
        return same(t1->left,t2->left)&&same(t1->right,t2->right);
    }
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t2)return 1;
        if(!t1)return 0;
        if(t1->val==t2->val){
            if(same(t1,t2))return 1;
        }
        if(checkSubTree(t1->left,t2))return 1;
        if(checkSubTree(t1->right,t2))return 1;
        return 0;
    }
};