// id:374919279
// runtime:84 ms
// memory:52.7 MB
// title:BiNode LCCI
// translatedTitle:BiNode
// questionId:1000019
// time:2022-10-20 19:45:22

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
    pair<TreeNode*,TreeNode*> dfs(TreeNode*x){
        TreeNode*head=new TreeNode();
        auto tail=head;
        if(x->left){
            auto [h,t]=dfs(x->left);
            tail->right=h;
            tail=t;
        }
        tail->right=x;
        x->left=nullptr;
        tail=x;
        if(x->right){
            auto [h,t]=dfs(x->right);
            tail->right=h;
            tail=t;
        }
        auto h=head->right;
        delete head;
        return {h,tail};
    }
    TreeNode* convertBiNode(TreeNode* root) {
        if(!root)return nullptr;
        auto [h,t]=dfs(root);
        t->right=nullptr;
        return h;
    }
};