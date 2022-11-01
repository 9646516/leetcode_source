// id:373945691
// runtime:28 ms
// memory:22.3 MB
// title:二叉搜索树中的中序后继
// translatedTitle:二叉搜索树中的中序后继
// questionId:1000313
// time:2022-10-17 20:54:04

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
    TreeNode*ans;
    int val;
    void dfs(TreeNode*x){
        if(ans)return;
        if(x->left)dfs(x->left);
        if(x->val>val&&!ans){
            ans=x;
        }
        if(x->right)dfs(x->right);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        ans=nullptr;
        val=p->val;
        dfs(root);
        return ans;
    }
};