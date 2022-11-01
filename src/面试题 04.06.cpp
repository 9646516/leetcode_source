// id:374544942
// runtime:44 ms
// memory:22.3 MB
// title:Successor LCCI
// translatedTitle:后继者
// questionId:100178
// time:2022-10-19 17:03:47

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)return nullptr;
        auto res=inorderSuccessor(root->left,p);
        if(res)return res; 
        if(root->val>p->val)return root;
        return inorderSuccessor(root->right,p);
    }
};