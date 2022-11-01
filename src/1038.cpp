// id:373950343
// runtime:4 ms
// memory:7.8 MB
// title:Binary Search Tree to Greater Sum Tree
// translatedTitle:从二叉搜索树到更大和树
// questionId:1114
// time:2022-10-17 21:05:32

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int xs;
    void dfs(TreeNode*x){
        xs+=x->val;
        if(x->left)dfs(x->left);
        if(x->right)dfs(x->right);
    }
    void dfs2(TreeNode*x){
        if(x->left)dfs2(x->left);
        int pre = x->val;
        x->val = xs;
        xs -= pre;
        if(x->right)dfs2(x->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)return root;
        xs=0;
        dfs(root);
        dfs2(root);
        return root;
    }
};