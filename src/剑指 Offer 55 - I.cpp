// id:373633902
// runtime:4 ms
// memory:18.4 MB
// title:二叉树的深度 LCOF
// translatedTitle:二叉树的深度
// questionId:100319
// time:2022-10-16 21:42:18

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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};