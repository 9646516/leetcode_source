// id:376955385
// runtime:16 ms
// memory:13.9 MB
// title:Lowest Common Ancestor of a Binary Tree
// translatedTitle:二叉树的最近公共祖先
// questionId:236
// time:2022-10-27 15:21:28

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        if(root==p||root==q)return root;
        auto l=lowestCommonAncestor(root->left,p,q);
        auto r=lowestCommonAncestor(root->right,p,q);
        if(l&&r)return root;
        if(l)return l;
        if(r)return r;
        return nullptr;
    }
};