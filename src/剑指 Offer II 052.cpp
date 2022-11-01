// id:373943194
// runtime:0 ms
// memory:8.1 MB
// title:展平二叉搜索树
// translatedTitle:展平二叉搜索树
// questionId:1000311
// time:2022-10-17 20:48:16

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
    pair<TreeNode*,TreeNode*>dfs(TreeNode*x){
        auto head=new TreeNode();
        auto tail=head;
        if(x->left){
            auto [h,t]=dfs(x->left);
            tail->right=h;
            tail=t;
        }
        tail->right=x;
        tail=x;
        if(x->right){
            auto [h,t]=dfs(x->right);
            tail->right=h;
            tail=t;
        }
        x->left=nullptr;
        auto h=head->right;
        delete head;
        return {h,tail};
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return nullptr;
        auto [h,t]=dfs(root);
        t->right=nullptr;
        return h;
    }
};