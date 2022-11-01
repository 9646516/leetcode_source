// id:373295334
// runtime:0 ms
// memory:8.8 MB
// title:二叉树的镜像  LCOF
// translatedTitle:二叉树的镜像
// questionId:100288
// time:2022-10-15 20:38:25

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
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)return root;
        auto L=root->left;
        auto R=root->right;
        root->left=R;
        root->right=L;
        if(root->left)mirrorTree(root->left);
        if(root->right)mirrorTree(root->right);
        return root;
    }
};